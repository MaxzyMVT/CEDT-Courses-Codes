package container;

import function.Function;
import util.Activation;
import util.GenRandom;

import java.util.Arrays;

public class Layer {
    private Neuron[] neurons;
    private Function function;

    public Layer(int inNeurons, int nNeurons, Function function) {
        setFunction(function);

        setNeurons(new Neuron[nNeurons]);
        for (int i = 0; i < nNeurons; i++) {
            double[] weights = new double[inNeurons];
            for (int j = 0; j < inNeurons; j++) {
                weights[j] = GenRandom.randomDouble(Neuron.getMinWeightValue(), Neuron.getMaxWeightValue());
            }
            getNeurons()[i] = new Neuron(weights, GenRandom.randomDouble(0, 1));;
        }
    }

    public Layer(double[] input) {
        Neuron[] neurons = new  Neuron[input.length];
        for (int i = 0; i < input.length; i++) {
            neurons[i] = new Neuron(input[i]);
        }

        setNeurons(neurons);
        setFunction(null);
    }

    public double applyActivation(double x) {
        return switch (getFunction()) {
            case SIGMOID -> Activation.sigmoid(x);
            case TANH ->  Activation.tanh(x);
            case RELU -> Activation.relu(x);
            case null -> throw new IllegalArgumentException("Unknown activation function: " + getFunction());
        };
    }

    public double applyActivationDerivative(double x) {
        return switch (getFunction()) {
            case SIGMOID -> Activation.sigmoidDerivative(x);
            case TANH ->  Activation.tanhDerivative(x);
            case RELU -> Activation.reluDerivative(x);
            case null -> throw new IllegalArgumentException("Unknown activation function: " + getFunction());
        };
    }

    public Neuron[] getNeurons() {
        return neurons;
    }

    public void setNeurons(Neuron[] neurons) {
        this.neurons = neurons;
    }

    public Function getFunction() {
        return function;
    }

    public void setFunction(Function function) {
        this.function = function;
    }
}
