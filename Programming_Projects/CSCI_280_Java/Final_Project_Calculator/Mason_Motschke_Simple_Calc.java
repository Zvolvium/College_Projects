// Mason Motschke - CSCI_280 - Final - 7/28/2022

import java.awt.event.*;
import javax.swing.*;

public class Mason_Motschke_Simple_Calc extends JFrame implements ActionListener {
  String s0, s1, s2;
  static JFrame frame;
  static JTextField field;

  Mason_Motschke_Simple_Calc (){
      s0 = s1 = s2 = "";
  }
  public static void main (String[] args){
      frame = new JFrame("Mason Motschke's Calculator");

      try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName()); }
      catch (Exception e) { System.err.println(e.getMessage()); }

      Mason_Motschke_Simple_Calc obj = new Mason_Motschke_Simple_Calc();
      field = new JTextField(8); field.setEditable(false);
      JPanel panel = new JPanel();

      /* Buttons */
      JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9; // Number Btns
      JButton eq, plus, minus, mult, div; // Operators
      JButton dec, clear, delete; // Additionals

      b0 = new JButton("0"); b1 = new JButton("1"); b2 = new JButton("2"); // Defining Btns - Numbers
      b3 = new JButton("3"); b4 = new JButton("4"); b5 = new JButton("5");
      b6 = new JButton("6"); b7 = new JButton("7"); b8 = new JButton("8"); b9 = new JButton("9");

      eq = new JButton("="); plus = new JButton("+"); minus = new JButton("-"); // Defining Btns - Operators
      mult = new JButton("*"); div = new JButton("/");

      dec = new JButton("."); clear = new JButton("Clear"); delete = new JButton("Delete"); // Defining Btns - Additionals

      b0.addActionListener(obj); b1.addActionListener(obj); b2.addActionListener(obj); // Setting Action Listeners to Btns
      b3.addActionListener(obj); b4.addActionListener(obj); b5.addActionListener(obj);
      b6.addActionListener(obj); b7.addActionListener(obj); b8.addActionListener(obj); b9.addActionListener(obj);

      eq.addActionListener(obj); plus.addActionListener(obj); minus.addActionListener(obj);
      mult.addActionListener(obj); div.addActionListener(obj);

      dec.addActionListener(obj); clear.addActionListener(obj); delete.addActionListener(obj);

      panel.add(field); // Adding All Btns to Calc
      panel.add(b7); panel.add(b8); panel.add(b9); panel.add(plus);
      panel.add(b4); panel.add(b5); panel.add(b6); panel.add(minus);
      panel.add(b1); panel.add(b2); panel.add(b3); panel.add(mult);
      panel.add(b0); panel.add(dec); panel.add(eq); panel.add(div);
      panel.add(clear); panel.add(delete);

      frame.add(panel); frame.setSize(125, 240); frame.setVisible(true);
  }

  public void actionPerformed (ActionEvent e){
        String s = e.getActionCommand();
 
        if ((s.charAt(0) >= '0' && s.charAt(0) <= '9') || s.charAt(0) == '.') {
            if (!s1.equals("")) s2 = s2 + s;
            else s0 = s0 + s;

            field.setText(s0 + s1 + s2); // Display String

        } else if (s.charAt(0) == 'C') { // Clear String on clear click
            s0 = s1 = s2 = "";
            field.setText(s0 + s1 + s2); // Display String

        } else if (s.charAt(0) == '=') {
            double result;
 
            if (s1.equals("+")) result = (Double.parseDouble(s0) + Double.parseDouble(s2));
            else if (s1.equals("-")) result = (Double.parseDouble(s0) - Double.parseDouble(s2));
            else if (s1.equals("/")) result = (Double.parseDouble(s0) / Double.parseDouble(s2));
            else result = (Double.parseDouble(s0) * Double.parseDouble(s2));
 
            field.setText(s0 + s1 + s2 + "=" + result); // Display String
 
            s0 = Double.toString(result); // convert it to string
            s1 = s2 = "";

        } else if (s.charAt(0) == 'D'){
          if (!s2.equals("")){
            s2 = s2.substring(0, s2.length() - 1);
          } else if (!s1.equals("")){
            s1 = s1.substring(0, s1.length() - 1);
          } else if (!s2.equals("")){
            s0 = s0.substring(0, s0.length() - 1);
          }

          field.setText(s0 + s1 + s2); // Display String

        } else {
            if (s1.equals("") || s2.equals("")) // if there was no operand
                s1 = s;
            else {
                double result; // else evaluate
 
                if (s1.equals("+")) result = (Double.parseDouble(s0) + Double.parseDouble(s2));
                else if (s1.equals("-")) result = (Double.parseDouble(s0) - Double.parseDouble(s2));
                else if (s1.equals("/")) result = (Double.parseDouble(s0) / Double.parseDouble(s2));
                else result = (Double.parseDouble(s0) * Double.parseDouble(s2));
 
                s0 = Double.toString(result); // convert to string
                s1 = s; s2 = "";
            }

            field.setText(s0 + s1 + s2);
        }
    }
}
