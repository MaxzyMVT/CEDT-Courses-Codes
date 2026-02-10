package container;

public class NeuronDemo {
    private Neuron n;

    public void demonstrate() {
        Neuron newN = new Neuron(new double[]{0.2, 0.3, 0.4}, 0.2);
        newN.setRangeWeight(0.1, 0.7);
        newN.setGradient(0.6);
        newN.setValue(1);

        setN(newN);
    }

    public Neuron getN() {
        return n;
    }

    public void setN(Neuron n) {
        this.n = n;
    }
}
