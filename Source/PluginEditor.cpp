/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
IRLoaderDemoAudioProcessorEditor::IRLoaderDemoAudioProcessorEditor (IRLoaderDemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    addAndMakeVisible(loadBtn);
    loadBtn.setButtonText("Load IR");
    loadBtn.onClick = [this]()
    {
        
    };
    
    setSize (600, 400);
}

IRLoaderDemoAudioProcessorEditor::~IRLoaderDemoAudioProcessorEditor()
{
}

//==============================================================================
void IRLoaderDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.setGradientFill(juce::ColourGradient::vertical(juce::Colour::fromRGB(40, 42, 53).darker(0.35f), getHeight(), juce::Colour::fromRGB(40, 42, 53).brighter(0.02), getHeight()*0.4));
    g.fillRect(getLocalBounds());
}

void IRLoaderDemoAudioProcessorEditor::resized()
{
    const auto btnX = getWidth() * 0.35;
    const auto btnY = getHeight()* 0.5;
    const auto btnWidth = getWidth() * 0.15;
    const auto btnHeight = btnWidth * 0.5;
    
    loadBtn.setBounds(btnX, btnY, btnWidth, btnHeight);
}
