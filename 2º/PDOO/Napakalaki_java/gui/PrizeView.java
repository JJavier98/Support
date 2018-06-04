/*  
 *  Programación y diseño orientado a objetos
 *  Grado en Ingeniería Informática
 * 
 *  2013 © Copyleft - All Wrongs Reserved
 *
 *  Ernesto Serrano <erseco@correo.ugr.es>
 * 
 */
package gui;

import napakalaki.Prize;

public class PrizeView extends javax.swing.JPanel {

    private Prize prizeModel;
    
    public void setPrize (Prize t) {
        
        prizeModel = t;

        String treasuresLevelsText = "<html>Tesoros: " + Integer.toString(prizeModel.getTreasures()) + "<br />"; 
        treasuresLevelsText += "Niveles: " + Integer.toString(prizeModel.getLevels()) + "</html>";
        
        lblTreasuresLevels.setText(treasuresLevelsText);
       

        //Finalizar con la siguiente orden para que los cambios se hagan efectivos
        repaint();
}
    
    /**
     * Creates new form TreasureView
     */
    public PrizeView() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblTreasuresLevels = new javax.swing.JLabel();

        lblTreasuresLevels.setText("<html>Tesoros: 0<br />Niveles: 0</html>");
        lblTreasuresLevels.setToolTipText("");

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(lblTreasuresLevels, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(lblTreasuresLevels, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
        );
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel lblTreasuresLevels;
    // End of variables declaration//GEN-END:variables
}
