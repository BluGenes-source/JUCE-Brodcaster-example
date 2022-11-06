#pragma once

#include <JuceHeader.h>
#include "TabPageOne.h"
#include "TabPageTwo.h"


class myDialog : public DialogWindow
{

};



struct MainTab : public TabbedComponent
    
{
	MainTab();
public:

};


class MainComponent  : public juce::Component,
                       public TabPageOne::Listener
   
{
public:
    
    MainComponent();
    ~MainComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;

    void setFormSize(TabPageOne*, bool isYes) override;

    MainTab maintab;
    TabPageOne tab1;
    TabPageTwo tab2;

   

    bool shouldSize;
    bool shouldPass;  // allows resizing after the button click to set form size
    

private:
    //==============================================================================
    // Your private member variables go here...
    ResizableBorderComponent m_resize;
    ComponentBoundsConstrainer  m_resizeLimits;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
