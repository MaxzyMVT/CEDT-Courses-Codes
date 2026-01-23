package logic;

public class Ticket {
	private int type;
	private int priceperstation;
	
	private Station start;
	private Station end;
	
	public Ticket(int type,Station start,Station end) {
		setType(type);
		setStation(start,end);
	}
	
	public int getType() {
		return type;
	}
	
	public int getPricePerStation() {
		return priceperstation;
	}

	public Station getStart() {
		return start;
	}
	
	public Station getEnd() {
		return end;
	}
	
	public void setType(int type) {
		this.type = (type < 0 || type > 2) ? 1 : type;
		this.priceperstation = switch (this.type) {
			case 0, 1 -> 30;
            case 2 -> 25;
			default -> 0;
		};
	}
	
	public void setStation(Station start,Station end) {
		this.start = start;
		this.end = end;
	}
	
	public double calculatePrice() {
		int stationDistance = getStationDistance(start, end);
		if (!this.isStationValid(start, end)) {
			return -1;
		}
        double price = stationDistance * getPricePerStation();
		if(this.getType()==0 && stationDistance > 4) {
			price *= 0.8;
		}
		else if(this.getType()==2) {
			price *= 0.6;
		}
		return price;
	}
	
	public String getDescription() {
		String typename = switch (type) {
            case 0 -> "Student";
            case 1 -> "Adult";
            case 2 -> getStationDistance(start, end) > 6 ? "Invalid" : "Elderly";
            default -> "Invalid";
        };
        return typename+" Ticket, from " + start.getName() + " to " + end.getName();
	}
	
	public boolean isStationValid(Station start,Station end) {
		if(start == end || start.getName().equals(end.getName())) {
			return false;
		}
		if (type == 2 && this.getStationDistance(start, end) > 6) {
			return false;
		}
        return type >= 0 && type <= 2;
    }
	
	public int getStationDistance(Station start,Station end) {
		return Math.abs(start.getNumber()-end.getNumber());
	}
	
}
