/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/
/*TODO: click anywhere and play a note. If the mouse is dragged change pitch. (2 directions + interval)
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class Pfm0AudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Pfm0AudioProcessor();
    ~Pfm0AudioProcessor();
//    afpvts()
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes)      override;

    AudioParameterBool* shouldPlaySound; //= false;
    AudioProcessorValueTreeState apvts;
    AudioParameterFloat* bgColor = nullptr;
 
    static void updateAutomatableParamter(RangedAudioParameter*, float value);
private:
    Random r;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pfm0AudioProcessor)
};
