import java.awt.*;
import javax.swing.*;

class DemoGraphics extends JFrame {
	
	public DemoGraphics() {
		super("Simple GUI");
		this.getContentPane().setBackground(new Color(70, 80, 70));
    }

    public void paint(Graphics g) {
		super.paint(g);
        String text = "Workshop 3: Graphics";
		Graphics2D g2d = (Graphics2D) g.create();

        // Configure Text and Lines
        g2d.setColor(Color.GREEN);

        g2d.setFont(new Font("MonoSpaced", Font.BOLD+Font.ITALIC, 18));
        FontMetrics fm = g2d.getFontMetrics();
        int x = ((getWidth() - fm.stringWidth(text)) / 2);
        int y = ((getHeight() - fm.getHeight()) / 2);

        g2d.drawRoundRect(x / 2 - 5, 70, getWidth() - (x) + 5, getHeight() / 2, 20, 20);
        
        // Add string and line to top section (Heading)
        g2d.drawString(text, x, 50);
        // Top Line
        g2d.drawLine(x - 5 , 55, x + 225, 55);
        // Bottom Line
        g2d.drawLine(x / 2 - 5, getHeight() - 40, getWidth() - 15, getHeight() - 40);
        
        // Draw Shapes
        g.setColor(Color.RED);
    	g.fillOval((x / 2 + 20), (y / 2 + 30), 50, 95);
        g.setColor(Color.YELLOW);
        g.fill3DRect((x / 2 + 22), (y / 2 + 22), 11, 14, true);
  
        // Add Image
        Image image=new ImageIcon("educ1.gif").getImage();
        g.drawImage(image, getWidth()/2  , y / 2 + 26, 90, 100, this);
        
        g2d.dispose();     
    }

    public void init() {
        // JPanel container for bottom section
        Container p = new JPanel();
		p.setBackground(new Color(70, 80, 70));
        
        // Add and configure button
	  	JButton b = new JButton("button");
	  	b.setForeground(Color.white);
	  	b.setBackground(p.getBackground());
        b.setToolTipText("This is a button");
          
        // Add and configure label with image
        JLabel l = new JLabel("label");
        l.setToolTipText("This is a label");
	  	l.setForeground(Color.white);
	  	ImageIcon icon = new ImageIcon("smiley.gif");
	  	l.setIcon(icon);
          
        // Configure JPanel layout and add components
		p.setLayout(new FlowLayout(1, 50, 5));
		p.add(l);
        p.add(b);
        
        // Add JPanel to JFrame
		this.getContentPane().add(BorderLayout.SOUTH, p);
    }
}
