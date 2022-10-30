#pragma once

#include <JuceHeader.h>


class TabPageTwo  : public juce::Component
{
public:
    TabPageTwo();
    ~TabPageTwo() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabPageTwo)
};
