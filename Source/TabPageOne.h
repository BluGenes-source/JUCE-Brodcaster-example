#pragma once

#include <JuceHeader.h>



class TabPageOne  : public juce::Component
{
public:
    TabPageOne();
    ~TabPageOne() override;

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

private:

    void setTheFormSize(bool canSize);

    bool canSetFormSize;
    
   TextButton aButton;

   ListenerList<Listener> listeners;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPageOne)
};
