package logic.stone;

public class HardStone extends Stone{
    protected int durability;

    public HardStone(int posX, int posY, int durability) {
        super(posX, posY);
        setDurability(durability);
    }

    @Override
    public void dig(int digPower) {
        setDurability(getDurability() - digPower);
        if(getDurability() <= 0){
            destroy();
        }
    }

    public int getDurability() {
        return durability;
    }

    public void setDurability(int durability) {
        this.durability = Math.max(0, Math.min(5, durability));
    }
}
