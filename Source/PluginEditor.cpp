/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfm0AudioProcessorEditor::Pfm0AudioProcessorEditor (Pfm0AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    cachedBgColor = processor.bgColor->get();
    setSize (400, 300);
    startTimerHz(20);
}

Pfm0AudioProcessorEditor::~Pfm0AudioProcessorEditor()
{
    Pfm0AudioProcessor::updateAutomatableParamter(processor.shouldPlaySound, false);
}

void Pfm0AudioProcessorEditor::timerCallback(){
    
    update();
}

void Pfm0AudioProcessorEditor::update(){
     cachedBgColor = processor.bgColor->get();
    repaint();
}
//==============================================================================
void Pfm0AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId).interpolatedWith(Colours::red, cachedBgColor));
    

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Pfm0AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void Pfm0AudioProcessorEditor::mouseUp(const MouseEvent &e)
{
//     Pfm0AudioProcessor::updateAutomatableParamter(processor.shouldPlaySound,!processor.shouldPlaySound-> get());
}

void Pfm0AudioProcessorEditor::mouseDown(const MouseEvent &e)
{
    //Get mouse position
    lastClickedPos = e.getPosition();
}

void Pfm0AudioProcessorEditor::mouseDrag(const MouseEvent &e){
    auto clickPos = e.getPosition();
    DBG(clickPos.toString());
    auto difY = jlimit(-1.0, 1.0, (clickPos.y - lastClickedPos.y)/static_cast<double>(getHeight()));
    difY = jmap((double)clickPos.y,0.0, (double)getHeight(), 1.0, 0.0);
    Pfm0AudioProcessor::updateAutomatableParamter(processor.bgColor, difY);
    update();
}
