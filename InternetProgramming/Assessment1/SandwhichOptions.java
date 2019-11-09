import java.util.HashMap;
import java.util.Map;

// SandwhichOptions class will contain 
class SandwhichOptions {
    private Map<String, Double> sandwhichTypes;
    private Map<String, Double> breadList;
    private String[] sauceList;
    private String[] extrasList;

    // Initialize variables for Sandwhiches
    SandwhichOptions() {
        // Possible extras
        extrasList = new String[] {"Avocado", "Mushrooms", "Olives", "Cheese", "Beef", "Ham", "Bacon", "Salami", "Chicken"};
        // Types of breads and their extra cost
        breadList = new HashMap<String, Double>();
        breadList.put("White", 0.00);
        breadList.put("Wheat", 0.00);
        breadList.put("Honey Oat", 1.00);
        // Sauce List
        sauceList = new String[] {"Barbeque", "Tomato"};
        // Possible sandwhiches
        sandwhichTypes = new HashMap<String, Double>();
        sandwhichTypes.put("Ultimate Club Sandwhich", 9.50);
        sandwhichTypes.put("Seafood", 9.00);
        sandwhichTypes.put("Chicken", 8.50);
        sandwhichTypes.put("Meatball", 8.50);
        sandwhichTypes.put("Veggie", 8.00);
        sandwhichTypes.put("Tuna", 7.50);
    }

    // ---- Get Lists ----
    public Map<String, Double> getSTypeList() {
        return sandwhichTypes;
    }

    public Map<String, Double> getBreadList() {
        return breadList;
    }

    public String[] getExtrasList() {
        return extrasList;
    }

    public String[] getSauceList() {
        return sauceList;
    }

    // ---- Get Price for sandwich parts ----
    public Double getSandwichCost(String s) {
        return sandwhichTypes.get(s);
    }

    public Double getBreadCost(String b) {
        return breadList.get(b);
    }
    // Calculate cost of a certain sandwhich, requires cost varying components of sandwhich.
    public Double getCost(String sType, String sBread, String[] sExtras) {
        Double cost = 0.00;
        cost += sandwhichTypes.get(sType);
        cost += breadList.get(sBread);
        for(String i : sExtras) {
            cost += 1.50;
        }
        return cost;
    }

}