import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.ArrayList;
import java.util.Map;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

class OrderGraphics extends JFrame {
    private static final long serialVersionUID = 1L;
    private final SandwhichOptions sOptions = new SandwhichOptions();
    private JList<String> extrasList;
    private JList<String> sTypesList;
    private JList<String> breadList;
    private ButtonGroup saucesBG;
    private JSpinner qSpinner;
    private JCheckBox dCheckBox;
    private Double sandwichCost = 0.00;
    private JTextField totalCost;
    private JTextArea oDescription;
    private String selectedSandwich;
    private Double sandwichTypeCost = 0.0;
    private String selectedBread;
    private Double breadCost = 0.0;
    private ArrayList<String> selectedExtras;
    private int extrasCount = 0;
    private String selectedSauce;
    private int selectedQuantity = 1;
    private Boolean selectedDelivery = false;
    private JLabel pAmount;
    private Boolean clearedOrder = false;
    private String description;

    OrderGraphics() {
        super("Sandwhich Order");
        this.setSize(600, 500);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.init();
        this.setVisible(true);
    }

    // Initialise GUI working from top down
    public void init() {
        // Create panel with GridBagLayout and a Constraints object for specifying constraints of each added component
        JPanel pane = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        Font topLabel = new Font("MonoSpaced", Font.BOLD, 16);

        // ---- Add top labels ----
        JLabel sLabel = new JLabel("Sandwich Type:");
        sLabel.setFont(topLabel);
        sLabel.setBorder(BorderFactory.createEmptyBorder(5, 10, 5, 30)); // T, L, B, R
        c.gridx = 0;
        c.gridy = 0;
        c.anchor = GridBagConstraints.LINE_START;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(0, 3, 0, 3);
        pane.add(sLabel, c);

        JLabel bsLabel = new JLabel("Bread & Sauce:");
        bsLabel.setFont(topLabel);
        bsLabel.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
        c.gridx = 1;
        pane.add(bsLabel, c);

        JLabel eLabel = new JLabel("Extras:");
        eLabel.setFont(topLabel);
        eLabel.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 10));
        c.gridx = 2;
        pane.add(eLabel, c);

        // ---- Add Lists ----
        JScrollPane scrollPane1 = new JScrollPane();
        Map<String, Double> sListMap = sOptions.getSTypeList();
        String[] sListArr = sListMap.keySet().toArray(new String[sListMap.size()]);
        sTypesList = new JList<>(sListArr);
        selectedSandwich = new String();
        sTypesList.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
        sTypesList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                selectedSandwich = sTypesList.getSelectedValue();
                if(selectedSandwich == null)
                    return;
                updateOrderDescription();
                sandwichTypeCost = sOptions.getSandwichCost(selectedSandwich);
                updateSandwichCost();
            }
        });
        c.gridx = 0;
        c.gridy = 1;
        c.gridheight = 3;
        scrollPane1.setViewportView(sTypesList);
        pane.add(scrollPane1, c);

        // Bread List with single select
        Map<String, Double> breadListMap = sOptions.getBreadList();
        String[] breadArr = breadListMap.keySet().toArray(new String[breadListMap.size()]);
        breadList = new JList<>(breadArr);
        selectedBread = new String();
        breadList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        breadList.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        breadList.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                selectedBread = breadList.getSelectedValue();
                if(selectedBread == null)
                    return;
                updateOrderDescription();
                breadCost = sOptions.getBreadCost(selectedBread);
                updateSandwichCost();
            }
        });
        c.gridx = 1;
        c.gridheight = 1;
        pane.add(breadList, c);

        // Extras List with custom multi-select
        JScrollPane scrollPane2 = new JScrollPane();
        String[] extrasArr = sOptions.getExtrasList();
        extrasList = new JList<>(extrasArr);
        selectedExtras = new ArrayList<String>();
        extrasList.setSelectionModel(new DefaultListSelectionModel() {
            @Override
            public void setSelectionInterval(int index0, int index1) {
                if(super.isSelectedIndex(index0)) {
                    super.removeSelectionInterval(index0, index1);
                    selectedExtras.remove(extrasList.getModel().getElementAt(index0));
                    extrasCount--;
                }
                else {
                    super.addSelectionInterval(index0, index1);
                    selectedExtras.add(extrasList.getModel().getElementAt(index0));
                    extrasCount++;
                }
                updateOrderDescription();
                updateSandwichCost();
            }
        });
        c.gridx = 2;
        c.gridheight = 3;
        scrollPane2.setViewportView(extrasList);
        pane.add(scrollPane2, c);

        // ---- Add Sauces ----
        saucesBG = new ButtonGroup();
        selectedSauce = new String();

        JCheckBox bbqSauce = new JCheckBox("BBQ");
        bbqSauce.addItemListener(new ItemListener(){
        
            @Override
            public void itemStateChanged(ItemEvent arg0) {
                if(clearedOrder)
                    return;
                if(bbqSauce.isSelected())
                    selectedSauce = "BBQ";
                updateOrderDescription();
            }
        });
        saucesBG.add(bbqSauce);
        c.gridx = 1;
        c.gridy = 2;
        c.gridheight = 1;
        pane.add(bbqSauce, c);

        JCheckBox tSauce = new JCheckBox("Tomato");
        tSauce.addItemListener(new ItemListener(){
        
            @Override
            public void itemStateChanged(ItemEvent arg0) {
                if(clearedOrder)
                    return;
                if(tSauce.isSelected())
                    selectedSauce = "Tomato";
                updateOrderDescription();
            }
        });
        c.gridy = 3;
        saucesBG.add(tSauce);
        pane.add(tSauce, c);

        // ---- Add Second layer labels ----
        JLabel pLabel = new JLabel("Price:");
        pLabel.setFont(topLabel);
        pLabel.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
        c.gridx = 0;
        c.gridy = 4;
        pane.add(pLabel, c);

        JLabel qLabel = new JLabel("Quantity:");
        qLabel.setFont(topLabel);
        qLabel.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
        c.gridx = 1;
        pane.add(qLabel, c);

        // ---- Add price label and quantity and delivery input ---- 
        pAmount = new JLabel("$0.00");
        pAmount.setFont(topLabel);
        pAmount.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
        c.gridx = 0;
        c.gridy = 5;
        pane.add(pAmount, c);

        qSpinner = new JSpinner();
        qSpinner.setModel(new SpinnerNumberModel(1, 1, 10, 1));
        qSpinner.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                if(clearedOrder) {
                    return;
                }
                selectedQuantity = (Integer) qSpinner.getValue();
                updateOrderDescription();
                updateTotalCost();
            }
        });
        c.gridx = 1;
        pane.add(qSpinner, c);

        dCheckBox = new JCheckBox("Delivery: ");
        dCheckBox.addItemListener(new ItemListener(){
        
            @Override
            public void itemStateChanged(ItemEvent arg0) {
                if(clearedOrder)
                    return;
                else if(dCheckBox.isSelected())
                    selectedDelivery = true;
                else
                    selectedDelivery = false;
                updateOrderDescription();
                updateTotalCost();
            }
        });
        dCheckBox.setHorizontalTextPosition(SwingConstants.LEFT);
        c.gridx = 2;
        pane.add(dCheckBox, c);

        // ---- Add Order Description & Total Cost ----
        oDescription = new JTextArea("# Sandwich Description\n\n");
        oDescription.setEditable(false);
        JScrollPane oDescrScroll = new JScrollPane(oDescription);
        Border oDescrBorder = BorderFactory.createLineBorder(Color.black);
        oDescription.setBorder(BorderFactory.createCompoundBorder(oDescrBorder, BorderFactory.createEmptyBorder(5, 50, 5, 50)));
        c.gridx = 0;
        c.gridy = 6;
        c.gridwidth = 2;
        pane.add(oDescrScroll, c);

        totalCost = new JTextField("Total cost: $0.00");
        totalCost.setEditable(false);
        c.gridx = 2;
        c.gridwidth = 1;
        pane.add(totalCost, c);

        // ---- Add Order buttons
        JButton orderButton = new JButton("Order");
        orderButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                orderSandwich();
            }
        });
        c.gridx = 0;
        c.gridy = 7;
        pane.add(orderButton, c);

        JButton clearButton = new JButton("Clear Order");
        clearButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                clearOrder();
            }
        });
        c.gridx = 1;
        pane.add(clearButton, c);

        this.getContentPane().add(BorderLayout.NORTH, pane);
    }

    // Update order description each time a component value is changed
    final void updateOrderDescription() {
        // Build string
        description = "# Sandwich Description\n";
        if(selectedQuantity > 0)
            description += selectedQuantity + "x:\n";
        if(!selectedSandwich.isEmpty() && selectedSandwich != null)
            description += "Sandwich Type: " + selectedSandwich + "\n";
        if(!selectedBread.isEmpty() && selectedBread != null)
            description += "Bread: " + selectedBread + "\n";
        if(!selectedSauce.isEmpty() && selectedSauce != null)
            description += "Sauce: " + selectedSauce + "\n";
        if(!selectedExtras.isEmpty()) {
            description += "Extras: " + "\n";
            for(String i : selectedExtras) {
                description += "- " + i + "\n";
            }
        }
        if(selectedDelivery)
            description += "\nDelivery: true\n";
        else
            description += "\nDelivery: false\n";
        
        // Display order description on GUI
        oDescription.setText(description);

        return;
    }

    // Update cost of sadnwhich each time a component value is changed
    final void updateSandwichCost() {
        sandwichCost = sandwichTypeCost;
        sandwichCost += breadCost;
        sandwichCost += extrasCount * 1.50;
        pAmount.setText("$" + sandwichCost.toString() + "0");
        updateTotalCost();
    }

    // Update total order cost each time a component value is changed
    final void updateTotalCost() {
        Double totCost = sandwichCost * selectedQuantity;
        if(selectedDelivery && totCost <= 27)
            totCost += 5.0;
        totalCost.setText("Total Cost: $" + totCost.toString());
    }

    // Popup dialog when user clicks order button
    final void orderSandwich() {
        JFrame frame = new JFrame();
        frame.resize(300, 300);
        JOptionPane.showMessageDialog(frame, description+"\nTotal Cost: "+totalCost.getText(), "Complete Order", JOptionPane.PLAIN_MESSAGE);
    }

    // Clear every order component and variable
    final void clearOrder() {
        // Variable used to prevent components listener executing when clearing order
        clearedOrder = true;

        // Reset GUI Components
        sTypesList.clearSelection();
        extrasList.clearSelection();
        breadList.clearSelection();
        saucesBG.clearSelection();
        qSpinner.setValue(1);
        dCheckBox.setSelected(false);
        
        // Reset variables
        sandwichCost = 0.00;
        sandwichTypeCost = 0.00;
        selectedBread = "";
        selectedSandwich = "";
        selectedDelivery = false;
        selectedExtras = new ArrayList<String>();
        selectedSauce = "";
        extrasCount = 0;
        selectedQuantity = 1;
        breadCost = 0.00;

        // Update interface components
        updateSandwichCost();
        updateOrderDescription();

        clearedOrder = false;
    }
}