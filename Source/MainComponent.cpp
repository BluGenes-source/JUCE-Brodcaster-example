#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent() : m_resize(this, nullptr) // &m_resizeLimits
{
	auto colour = findColour(ResizableWindow::backgroundColourId);

	m_resizeLimits.setSizeLimits(500, 200, 800, 400);
	addAndMakeVisible(&m_resize);
	addAndMakeVisible(maintab);
	

	tab1.addListener(this);
	maintab.addTab("Tab 1", colour, &tab1, false);    
	maintab.addTab("Tab 2", colour, &tab2, false);  
	shouldSize = false;
	shouldPass = true;
	
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
	tab1.removeListener(this);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& /*g */)  // comment removes compiler warning
{
   
}

void MainComponent::resized()
{
	
	m_resize.setBounds(getLocalBounds().removeFromRight(20).removeFromBottom(20));
	
	
	if (!shouldPass)
	{
		if (shouldSize)         
			setSize(600, 200);
		else
			setSize(600, 400);
		shouldPass = true;      
	}
	auto area = getLocalBounds();

	maintab.setBounds(area);
}

void MainComponent::setFormSize(TabPageOne*, bool isYes)
{
	if (isYes)
	{
		shouldSize = true;
	}
	else
	{
		shouldSize = false;
	}
		shouldPass = false;
        resized();
	
}


MainTab::MainTab() : TabbedComponent(TabbedButtonBar::TabsAtTop)
{
	auto color = findColour(ResizableWindow::backgroundColourId);
}
