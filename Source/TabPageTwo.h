#pragma once

#include <JuceHeader.h>

class myChangeTab2Listener : public juce::ChangeListener
{
public:
	void changeListenerCallback(ChangeBroadcaster* /*source*/) override;


};


class TabPageTwo  : public juce::Component,
	                public myChangeTab2Listener,
	                public ChangeBroadcaster

{
public:
    TabPageTwo();
    ~TabPageTwo() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void changeListenerCallback(ChangeBroadcaster* /*source*/) override;


    Label HelloLabel2;

    TextButton HiTab1Button;
    void hiTab1ButtonOnClick();
private:

    
    ListenerList<myChangeTab2Listener::ChangeListener> myChangeTab2Listeners;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPageTwo)
};
