/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TpfirstpluginAudioProcessorEditor::TpfirstpluginAudioProcessorEditor (TpfirstpluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
	
	//and set the slider's styles and etc;

	gainSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	//textbox;
	gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
	//and the range;
	gainSlider.setRange(-48.0, 0.0);
	//what's the period;
	gainSlider.setValue(-1.0);
	//aaand we need to make our component listening for the changes;
	gainSlider.addListener(this);
	addAndMakeVisible(gainSlider);
	//we add as a child of our component(gainSlider is the child);
}

TpfirstpluginAudioProcessorEditor::~TpfirstpluginAudioProcessorEditor()
{
}

//==============================================================================
void TpfirstpluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));


}

void TpfirstpluginAudioProcessorEditor::resized()
{
  //draw the Slider itself!;
	gainSlider.setBounds(getLocalBounds());
}

//we put the function itself;

void TpfirstpluginAudioProcessorEditor::sliderValueChanged(Slider *slider) 
{
	//Wtf is happening when we change the value? Well, this!

	if (slider == &gainSlider)
	{
		processor.rawVolume = pow(10, gainSlider.getValue() / 20);
	}

}