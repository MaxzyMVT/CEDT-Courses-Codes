package logic;

import java.util.ArrayList;

public class Database {
    private ArrayList<Player> playerList;
    private ArrayList<Region> regionList;

    public Database() {
        this(new ArrayList<>(), new ArrayList<>());
    }

    public Database(ArrayList<Player> playerList, ArrayList<Region> regionList) {
        setPlayerList(playerList);
        setRegionList(regionList);
    }

    public Player addPlayer(String name, Region region) {

        if (DatabaseUtil.isPlayerExists(getPlayerList(), name)) {
            throw new IllegalArgumentException("Player already exists!");
        }

        Player newPlayer = new Player(name);
        region.addPlayerToRegion(newPlayer);
        getPlayerList().add(newPlayer);
        return newPlayer;
    }

    public boolean addRegion(String name) {
        if ( DatabaseUtil.isRegionExists(getRegionList(), name) ) {
            return false;
        }
        Region newRegion = new Region(name);
        regionList.add(newRegion);
        return true;
    }

    public Region getRegionByName(String name) {
        for (Region r : getRegionList()) {
            if (r.getName().equals(name)) {
                return r;
            }
        }
        return null;
    }

    public void addQuest(Player author, Region region, String name, String description) {
        Quest quest = new Quest(author, region, name, description);
        for ( Region r : getRegionList() ) {
            if ( r.getName().equals(region.getName()) ) {
                r.addQuestToRegion(quest);
            }
        }
    }

    public ArrayList<Player> getPlayerList() {
        return playerList;
    }

    public void setPlayerList(ArrayList<Player> playerList) {
        this.playerList = playerList;
    }

    public ArrayList<Region> getRegionList() {
        return regionList;
    }

    public void setRegionList(ArrayList<Region> regionList) {
        this.regionList = regionList;
    }
}
