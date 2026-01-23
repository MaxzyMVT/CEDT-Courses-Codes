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
		this.type = type;
	}
	
	public void setStation(Station start,Station end) {
		this.start = start;
		this.end = end;
	}
	
	public double calculatePrice() {
		double price = 0.0;
		int stationDistance = getStationDistance(start, end);

		switch(type) {
			case 0:
				price = stationDistance * 30.0;
				if(stationDistance > 4)
					price *= 0.8;
				break;
			case 1:
				price = stationDistance * 30.0;
				break;
			case 2:
				price = stationDistance * 25.0 * 0.6;
				break;
			default:
				price = 0.0;
		}
	}
	
	public String getDescription() {
		String typename;
		
		switch(type) {
		case 0:
			typename = "Student";
			break;
		case 1:
			typename = "Adult";
			break;
		case 2:
			typename = "Elderly";
			break;
		default:
			typename = "Invalid";
		}
		
		return typename+" Ticket, from " + start.getName() + " to " + end.getName();
	}
	
	public boolean isStationValid(Station start,Station end) {

		if(type < 0 || type > 2)
			return false;
		if(!CPTSMachine.isStationExist(start) || !CPTSMachine.isStationExist(end))
			return false;
		if (type == 2 && this.getStationDistance(start, end) > 6)
			return false;
		if (start == end || start.getName().equals(end.getName()))
			return false;
		return true;
	}
	
	public int getStationDistance(Station start,Station end) {
		return Math.abs(start.getNumber()-end.getNumber());
	}
	
}
