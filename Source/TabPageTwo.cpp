#include <JuceHeader.h>
#include "TabPageTwo.h"



//==============================================================================
TabPageTwo::TabPageTwo()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
	addAndMakeVisible(HelloLabel2);
	HelloLabel2.setText("waiting for change message from Tab 1...", dontSendNotification);

    addAndMakeVisible(HiTab1Button);
    HiTab1Button.setButtonText("Say Hi To Tab1!");
    HiTab1Button.onClick = [this] {hiTab1ButtonOnClick();  };

}

TabPageTwo::~TabPageTwo()
{
}

void TabPageTwo::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("TabPage2 - Nothing to see here.. move along please.", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void TabPageTwo::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    HelloLabel2.setBounds((getWidth() / 2) - 150, 100, 300, 34);
    HiTab1Button.setBounds((getWidth() / 2) - 150, 200, 300, 34);

 
}

void TabPageTwo::changeListenerCallback(ChangeBroadcaster* /*source*/)
{
    HelloLabel2.setText("Hello from Tab 1 !!", dontSendNotification);
      
}

void TabPageTwo::hiTab1ButtonOnClick()
{
    sendChangeMessage();
}

void myChangeTab2Listener::changeListenerCallback(ChangeBroadcaster* /*source*/)
{
    DBG("clicked called from tab 1");  // never called
}
