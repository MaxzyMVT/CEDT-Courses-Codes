package container;

public class Neuron {
    private static double minWeightValue;
    private static double maxWeightValue;
    private double[] weights;
    private double gradient;
    private double bias;
    private double value;

    public Neuron(double[] weights, double bias) {
        setWeights(weights);
        setBias(bias);
    }

    public Neuron(double value) {
        setValue(value);
        setBias(-1);
        setGradient(-1);
        setWeights(null);
    }

    public static void setRangeWeight(double min, double max) {
        minWeightValue = min;
        maxWeightValue = max;
    }

    public static double getMinWeightValue() {
        return minWeightValue;
    }

    public static double getMaxWeightValue() {
        return maxWeightValue;
    }

    public double[] getWeights() {
        return weights;
    }

    public void setWeights(double[] weights) {
        this.weights = weights;
    }

    public double getGradient() {
        return gradient;
    }

    public void setGradient(double gradient) {
        this.gradient = gradient;
    }

    public double getBias() {
        return bias;
    }

    public void setBias(double bias) {
        this.bias = bias;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }
}
