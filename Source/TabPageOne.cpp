#include <JuceHeader.h>
#include "TabPageOne.h"


TabPageOne::TabPageOne()
{
     
    addAndMakeVisible(aButton);
    aButton.onClick = [this] {aButtonClicked(); };
    aButton.setButtonText("Show Less");
    aButton.setClickingTogglesState(true);
    canSetFormSize = false;

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
}

void TabPageOne::aButtonClicked()
{
    if (aButton.getToggleState())
    {
        canSetFormSize = true;
        aButton.setButtonText("Show More");
    }
    else
    {
        canSetFormSize = false;
        aButton.setButtonText("Show Less");
    }
    setTheFormSize(canSetFormSize);
}

void TabPageOne::setTheFormSize(bool canSize)
{
    listeners.call([this, canSize](Listener& l) { l.setFormSize(this, canSetFormSize); });
}
