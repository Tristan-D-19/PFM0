/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "PluginProcessor.h"


//==============================================================================
/**
*/
struct PfmpprojectAudioProccessor;
 
class Pfm0AudioProcessorEditor  : public AudioProcessorEditor, public Timer
{
public:
    Pfm0AudioProcessorEditor (Pfm0AudioProcessor&);
    ~Pfm0AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void mouseDown(const MouseEvent &e) override;
    void mouseUp(const MouseEvent &e) override;
    void mouseDrag(const MouseEvent &e) override;
    void timerCallback() override;
    
private:
    Point<int> lastClickedPos;
    void update();
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Pfm0AudioProcessor& processor;
    float cachedBgColor = 0.f;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pfm0AudioProcessorEditor)
};
