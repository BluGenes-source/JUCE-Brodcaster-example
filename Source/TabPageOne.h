#pragma once

#include <JuceHeader.h>

// since there are two changeBroadcasters being used, you need a custom changeListener class to be able to separate the two,
// one for each tab component

class myChangeTab1Listener : public juce::ChangeListener
{
public:
	void     changeListenerCallback(ChangeBroadcaster* /*source*/) override;

};


class TabPageOne  : public juce::Component,
                    public myChangeTab1Listener,
                    public ChangeBroadcaster
{
public:
    TabPageOne();
    ~TabPageOne() override;

    
    // this is custom listener that uses custom parameters
    // to use this, it would be exactly like using a button listener for example.
    // all you do is add className :: Listener to what ever you want to have use it.  In this case, it is
    // TabPageOne :: Listener..
    class Listener
    {
    public:
        virtual ~Listener() = default;

        // add more virtual functions as needed here (the "multi" in this example, even though there is just this one)
        virtual void setFormSize(TabPageOne*, bool isYes) = 0;

    };

    void addListener(Listener* listenerToAdd);
    void removeListener(Listener* listenerToRemove);

    void paint (juce::Graphics&) override;
    void resized() override;

    void aButtonClicked();
    void changeListenerCallback(ChangeBroadcaster* /*source*/) override;

    void hiTab2ButtonOnClick();
    void aboutButtonOnClick();

	Label HelloLabel1;

   TextButton HiTab2Button;
   
  
   
private:

    void setTheFormSize(bool canSize);

    bool canSetFormSize;
    
   TextButton aButton;
   ListenerList<myChangeTab1Listener::ChangeListener> myChangeTab1Listeners;
   ListenerList<Listener> listeners;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPageOne)
};
