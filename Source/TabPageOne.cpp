#include <JuceHeader.h>
#include "TabPageOne.h"




TabPageOne::TabPageOne()
{
  
    addAndMakeVisible(aButton);
    aButton.onClick = [this] {aButtonClicked(); };
    aButton.setButtonText("Show Less - Custom Listener");
    aButton.setClickingTogglesState(true);
    canSetFormSize = false;

    addAndMakeVisible(HelloLabel1);
    HelloLabel1.setText("waiting for change message from Tab 2...", dontSendNotification);

    addAndMakeVisible(HiTab2Button);
    HiTab2Button.setButtonText("Say Hi To Tab2!");
	HiTab2Button.onClick = [this] {hiTab2ButtonOnClick(); };


}

TabPageOne::~TabPageOne()
{
    
}

void TabPageOne::addListener(Listener* listenerToAdd)
{
    listeners.add(listenerToAdd);
}

void TabPageOne::removeListener(Listener* listenerToRemove)
{
	jassert(listeners.contains(listenerToRemove));
	listeners.remove(listenerToRemove);
}

void TabPageOne::paint (juce::Graphics& g)
{
   

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("TabPageOne", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void TabPageOne::resized()
{
    aButton.setBounds(10, 10, 250, 40);
    HelloLabel1.setBounds((getWidth() / 2) - 150, 100, 300, 34);
    HiTab2Button.setBounds((getWidth() / 2) - 150, 200, 300, 34);
}

void TabPageOne::aButtonClicked()
{
    if (aButton.getToggleState())
    {
        canSetFormSize = true;
        aButton.setButtonText("Show More - Custom Listener");
    }
    else
    {
        canSetFormSize = false;
        aButton.setButtonText("Show Less - Custom Listener");
    }
    setTheFormSize(canSetFormSize);
}

void TabPageOne::changeListenerCallback(ChangeBroadcaster* /*source*/)
{
    
    HelloLabel1.setText("Hello from Tab 2 !!! Received ChangeMessage!", dontSendNotification);
    
}



void TabPageOne::hiTab2ButtonOnClick()
{
    sendChangeMessage();
}

void TabPageOne::setTheFormSize(bool canSize)
{
    listeners.call([this, canSize](Listener& l) { l.setFormSize(this, canSetFormSize); });
}

void myChangeTab1Listener::changeListenerCallback(ChangeBroadcaster* /*source*/)
{
   // required but never called..
}
