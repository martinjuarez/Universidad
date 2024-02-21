package Ventana;

import Controlador.Matriz;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;

public class Ventana extends javax.swing.JFrame {
    int columnas;
    int filas;
    public Ventana(Matriz temp) {
        //Constructor con parametros de tipo matriz
        initComponents();
        this.getContentPane().setBackground(new Color(48, 131, 136));
        jButton31.setVisible(false);
        jButton34.setVisible(false);
        jButton35.setVisible(false);
        jButton36.setVisible(false);
        jButton37.setVisible(false);
        jButton38.setVisible(false);
        jButton39.setVisible(false);
        jButton40.setVisible(false);
        jButton41.setVisible(false);
        jButton42.setVisible(false);
        columnas=temp.getColumnas();
        filas=temp.getFilas();
        int i,j,k=temp.getIds();
        int[][] lab = temp.getMatriz();
        int[] aux = temp.getColores();
        String renglon="";
        //se crea una matriz de botones
        JButton[][] MatrizBotones = new JButton[filas][columnas];
        for(i = 0; i < filas; i++) {
            for(j = 0; j < columnas; j++) {
                //se recorre la matriz y se le da sus atributos, eltipo de terreno, color etc
                JButton a = new JButton();
                //estos ifs anidados son para darle un color y tipo de terreno por default depues se le asiganara funcion para asiganarles color y tipo de terreno
                if(lab[i][j]==aux[0]){
                    System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                    a.setBackground(Color.black);
                    a.setBorderPainted(false);
                    a.setForeground(Color.white);
                    a.setText(Integer.toString(lab[i][j]));
                    //ImageIcon iconobtn = new ImageIcon("src/Imagenes/a.png");
                    //a.setIcon(iconobtn);
                    renglon = " y soy Montaña ";
                    jButton31.setVisible(true);
                    jButton31.setForeground(Color.white);
                    jButton31.setBackground(Color.black);
                    jButton31.setText(Integer.toString(aux[0]));
                }else if(lab[i][j]==aux[1]){
                    if(1<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(new Color(250, 191, 143));
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Camino ");
                        renglon = " y soy Camino ";
                        jButton34.setVisible(true);
                        jButton34.setText(Integer.toString(aux[1]));
                        jButton34.setBackground(new Color(250, 191, 143));
                    }
                }else if(lab[i][j]==aux[2]){
                    if(2<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(new Color(0,176,240));
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Agua ");
                        renglon = " y soy Agua ";
                        jButton35.setVisible(true);
                        jButton35.setText(Integer.toString(aux[2]));
                        jButton35.setBackground(new Color(0,176,240));
                    }
                }else if(lab[i][j]==aux[3]){
                    if(3<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(new Color(255,192,0));
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Arena ");
                        renglon = " y soy Arena ";
                        jButton36.setVisible(true);
                        jButton36.setText(Integer.toString(aux[3]));
                        jButton36.setBackground(new Color(255,192,0));
                    }
                }else if(lab[i][j]==aux[4]){
                    if(4<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(new Color(155,187,89));
                        a.setBorderPainted(false);
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Bosque ");
                        a.setText(Integer.toString(lab[i][j]));
                        renglon = " y soy Bosque ";
                        jButton37.setVisible(true);
                        jButton37.setText(Integer.toString(aux[4]));
                        jButton37.setBackground(new Color(155,187,89));
                    }
                }else if(lab[i][j]==aux[5]){
                    if(5<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(new Color(178,161,199));
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Pantano");
                        renglon = " y soy Pantano";
                        jButton38.setVisible(true);
                        jButton38.setText(Integer.toString(aux[5]));
                        jButton38.setBackground(new Color(178,161,199));
                    }
                }else if(lab[i][j]==aux[6]){
                    if(6<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(Color.white);
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Nieve ");
                        renglon = " y soy Nieve ";
                        jButton39.setVisible(true);
                        jButton39.setText(Integer.toString(aux[6]));
                        jButton39.setBackground(Color.white);
                    }
                }else if(lab[i][j]==aux[7]){
                    if(7<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(Color.red);
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Nieve ");
                        renglon = " y soy Lava ";
                        jButton40.setVisible(true);
                        jButton40.setText(Integer.toString(aux[7]));
                        jButton40.setBackground(Color.red);
                    }
                }else if(lab[i][j]==aux[8]){
                    if(8<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(Color.ORANGE);
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Nieve ");
                        renglon = " y soy rocoso ";
                        jButton41.setVisible(true);
                        jButton41.setText(Integer.toString(aux[8]));
                        jButton41.setBackground(Color.ORANGE);
                    }
                }else if(lab[i][j]==aux[9]){
                    if(9<k){
                        System.out.println("i: "+i+", "+"j: "+j+" "+lab[i][j]);
                        a.setBackground(Color.GRAY);
                        a.setBorderPainted(false);
                        a.setText(Integer.toString(lab[i][j]));
                        //a.setToolTipText(Integer.toString(i)+","+Integer.toString(j)+" y soy Nieve ");
                        renglon = " y soy calizo ";
                        jButton42.setVisible(true);
                        jButton42.setText(Integer.toString(aux[9]));
                        jButton41.setBackground(Color.GRAY);
                    }
                }
                //Este swith es para agregar un mensaje en cada boton que diga su cordenada y su tipo de terreno
                switch(i){
                    case 0:
                        a.setToolTipText("A,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 1:
                        a.setToolTipText("B,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 2:
                        a.setToolTipText("C,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 3:
                        a.setToolTipText("D,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 4:
                        a.setToolTipText("E,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 5:
                        a.setToolTipText("F,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 6:
                        a.setToolTipText("G,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 7:
                        a.setToolTipText("H,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 8:
                        a.setToolTipText("I,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 9:
                        a.setToolTipText("J,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 10:
                        a.setToolTipText("K,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 11:
                        a.setToolTipText("M,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 12:
                        a.setToolTipText("N,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 13:
                        a.setToolTipText("O,"+Integer.toString(j+1)+ renglon);
                        break;
                    case 14:
                        a.setToolTipText("P,"+Integer.toString(j+1)+ renglon);
                        break;
                    default:
                        break;
                }
                a.setBounds(j*81+40, i*41+40, 80, 40);//se le da una posicion en la vetana y un tamaño a los botones
                //MatrizBotones[i][j].setBackground(SystemColor.MAGENTA);
                MatrizBotones[i][j]= a;
                MatrizBotones[i][j].setVisible(true);
                
                //funcion para hacer que se los botones ecuchen y sean sensibles al mause
                MatrizBotones[i][j].addActionListener(new ActionListener(){
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        //Click(a);
                        Cargar(a);//Funcion futura para cargar perosonajes
                    }
                });
                this.add(MatrizBotones[i][j]); // se dibuja la matriz
            }
        }
    }
 
    private void Cargar(JButton btn){
        btn.setBackground(new Color(255,174,201)); // aqui se pone un color experimental para simular un personaje o una casilla de inicial o final
    }
    //Constructor sin parametro de tipo matriz para que funcione el jpanel
    private Ventana() {
        initComponents();
        JButton a = new JButton();
        //ImageIcon iconobtn = new ImageIcon("src//Imagenes//a.png");
        //a.setIcon(iconobtn);
        //a.setIcon(iconobtn);
        a.setBackground(Color.MAGENTA);
        a.setBounds(50,50,75,75);
        a.setText("ds");
        a.setVisible(true);
        //a.setIcon(iconobtn);
        this.add(a);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton7 = new javax.swing.JButton();
        jButton8 = new javax.swing.JButton();
        jButton9 = new javax.swing.JButton();
        jButton10 = new javax.swing.JButton();
        jButton13 = new javax.swing.JButton();
        jButton14 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton11 = new javax.swing.JButton();
        jButton12 = new javax.swing.JButton();
        jButton15 = new javax.swing.JButton();
        jButton16 = new javax.swing.JButton();
        jButton17 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton18 = new javax.swing.JButton();
        jButton19 = new javax.swing.JButton();
        jButton20 = new javax.swing.JButton();
        jButton21 = new javax.swing.JButton();
        jButton22 = new javax.swing.JButton();
        jButton23 = new javax.swing.JButton();
        jButton24 = new javax.swing.JButton();
        jButton25 = new javax.swing.JButton();
        jButton26 = new javax.swing.JButton();
        jButton27 = new javax.swing.JButton();
        jButton28 = new javax.swing.JButton();
        jButton29 = new javax.swing.JButton();
        jButton30 = new javax.swing.JButton();
        jButton31 = new javax.swing.JButton();
        jButton32 = new javax.swing.JButton();
        jButton33 = new javax.swing.JButton();
        jButton34 = new javax.swing.JButton();
        jButton35 = new javax.swing.JButton();
        jButton36 = new javax.swing.JButton();
        jButton37 = new javax.swing.JButton();
        jButton38 = new javax.swing.JButton();
        jButton39 = new javax.swing.JButton();
        jButton40 = new javax.swing.JButton();
        jButton41 = new javax.swing.JButton();
        jButton42 = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem2 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setBackground(new java.awt.Color(255, 0, 0));
        setLocation(new java.awt.Point(-7, 0));
        setMinimumSize(new java.awt.Dimension(708, 730));
        setPreferredSize(new java.awt.Dimension(1379, 734));

        jButton3.setText("...");
        jButton3.setPreferredSize(new java.awt.Dimension(40, 40));

        jButton4.setText("B");
        jButton4.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton7.setText("C");
        jButton7.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton8.setText("D");
        jButton8.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton9.setText("E");
        jButton9.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton10.setText("F");
        jButton10.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton13.setText("G");
        jButton13.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton14.setText("H");
        jButton14.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton5.setText("I");
        jButton5.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton6.setText("J");
        jButton6.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton11.setText("K");
        jButton11.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton12.setText("M");
        jButton12.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton15.setText("N");
        jButton15.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton16.setText("O");
        jButton16.setPreferredSize(new java.awt.Dimension(40, 42));
        jButton16.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton16ActionPerformed(evt);
            }
        });

        jButton17.setText("P");
        jButton17.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton1.setText("2");
        jButton1.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton2.setText("1");
        jButton2.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton18.setText("4");
        jButton18.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton19.setText("3");
        jButton19.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton20.setText("6");
        jButton20.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton21.setText("5");
        jButton21.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton22.setText("8");
        jButton22.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton23.setText("7");
        jButton23.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton24.setText("9");
        jButton24.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton25.setText("11");
        jButton25.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton26.setText("10");
        jButton26.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton27.setText("12");
        jButton27.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton28.setText("12");
        jButton28.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton29.setText("15");
        jButton29.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton30.setText("13");
        jButton30.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton31.setText("jButton31");
        jButton31.setBorderPainted(false);
        jButton31.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton31ActionPerformed(evt);
            }
        });

        jButton32.setText("14");
        jButton32.setPreferredSize(new java.awt.Dimension(82, 40));

        jButton33.setText("A");
        jButton33.setPreferredSize(new java.awt.Dimension(40, 42));

        jButton34.setText("jButton34");
        jButton34.setBorderPainted(false);

        jButton35.setText("jButton35");
        jButton35.setBorderPainted(false);

        jButton36.setText("jButton36");
        jButton36.setBorderPainted(false);

        jButton37.setText("jButton37");
        jButton37.setBorderPainted(false);

        jButton38.setText("jButton38");
        jButton38.setBorderPainted(false);

        jButton39.setText("jButton39");
        jButton39.setBorderPainted(false);

        jButton40.setText("jButton40");
        jButton40.setBorderPainted(false);

        jButton41.setText("jButton41");
        jButton41.setBorderPainted(false);

        jButton42.setText("jButton42");
        jButton42.setBorderPainted(false);

        jMenu1.setText("Juego");

        jMenuItem1.setText("Jugar");
        jMenu1.add(jMenuItem1);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("Arbol");

        jMenuItem2.setText("Imprimir");
        jMenu2.add(jMenuItem2);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(120, 120, 120)
                                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(39, 39, 39)
                                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(201, 201, 201)
                                .addComponent(jButton19, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(80, 80, 80)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(81, 81, 81)
                                .addComponent(jButton20, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(jButton21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(242, 242, 242)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton26, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(81, 81, 81)
                                .addComponent(jButton28, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(80, 80, 80)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton30, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(81, 81, 81)
                                .addComponent(jButton32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addComponent(jButton16, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton10, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton15, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton17, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(1173, 1173, 1173)
                        .addComponent(jButton29, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(282, 282, 282)
                        .addComponent(jButton18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(606, 606, 606)
                        .addComponent(jButton22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(849, 849, 849)
                        .addComponent(jButton25, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(930, 930, 930)
                        .addComponent(jButton27, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(687, 687, 687)
                        .addComponent(jButton24, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(525, 525, 525)
                        .addComponent(jButton23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jButton33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButton31)
                    .addComponent(jButton34)
                    .addComponent(jButton35)
                    .addComponent(jButton36)
                    .addComponent(jButton37)
                    .addComponent(jButton38)
                    .addComponent(jButton39)
                    .addComponent(jButton40)
                    .addComponent(jButton41)
                    .addComponent(jButton42)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton19, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton20, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton21, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton26, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton28, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton30, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton32, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(492, 492, 492)
                        .addComponent(jButton16, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(123, 123, 123)
                        .addComponent(jButton9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(369, 369, 369)
                        .addComponent(jButton11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(164, 164, 164)
                        .addComponent(jButton10, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(328, 328, 328)
                        .addComponent(jButton6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(451, 451, 451)
                        .addComponent(jButton15, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(82, 82, 82)
                        .addComponent(jButton8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(246, 246, 246)
                        .addComponent(jButton14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(205, 205, 205)
                        .addComponent(jButton13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(533, 533, 533)
                        .addComponent(jButton17, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(41, 41, 41)
                        .addComponent(jButton7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(287, 287, 287)
                        .addComponent(jButton5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(410, 410, 410)
                        .addComponent(jButton12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
            .addComponent(jButton29, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton22, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton25, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton27, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton24, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addComponent(jButton23, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addGroup(layout.createSequentialGroup()
                .addGap(39, 39, 39)
                .addComponent(jButton33, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGroup(layout.createSequentialGroup()
                .addGap(37, 37, 37)
                .addComponent(jButton31)
                .addGap(11, 11, 11)
                .addComponent(jButton34)
                .addGap(11, 11, 11)
                .addComponent(jButton35)
                .addGap(11, 11, 11)
                .addComponent(jButton36)
                .addGap(11, 11, 11)
                .addComponent(jButton37)
                .addGap(11, 11, 11)
                .addComponent(jButton38)
                .addGap(11, 11, 11)
                .addComponent(jButton39)
                .addGap(11, 11, 11)
                .addComponent(jButton40)
                .addGap(11, 11, 11)
                .addComponent(jButton41)
                .addGap(11, 11, 11)
                .addComponent(jButton42))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton16ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton16ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jButton16ActionPerformed

    private void jButton31ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton31ActionPerformed
        
    }//GEN-LAST:event_jButton31ActionPerformed
    
    private void camCol(Matriz temp,int y){
        int i,j;
        JColorChooser aux= new JColorChooser();
        aux.showDialog(null,"Seleccionar un color",Color.gray);
        Color col;
        col = aux.getColor();
        MenuColor a = new MenuColor();
        
        for(i=0;i<filas;i++){
            for(j=0;j<columnas;j++){
                //MatrizBotones[i][j]          
            }
        }
    }
    
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Ventana.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Ventana().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton10;
    private javax.swing.JButton jButton11;
    private javax.swing.JButton jButton12;
    private javax.swing.JButton jButton13;
    private javax.swing.JButton jButton14;
    private javax.swing.JButton jButton15;
    private javax.swing.JButton jButton16;
    private javax.swing.JButton jButton17;
    private javax.swing.JButton jButton18;
    private javax.swing.JButton jButton19;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton20;
    private javax.swing.JButton jButton21;
    private javax.swing.JButton jButton22;
    private javax.swing.JButton jButton23;
    private javax.swing.JButton jButton24;
    private javax.swing.JButton jButton25;
    private javax.swing.JButton jButton26;
    private javax.swing.JButton jButton27;
    private javax.swing.JButton jButton28;
    private javax.swing.JButton jButton29;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton30;
    private javax.swing.JButton jButton31;
    private javax.swing.JButton jButton32;
    private javax.swing.JButton jButton33;
    private javax.swing.JButton jButton34;
    private javax.swing.JButton jButton35;
    private javax.swing.JButton jButton36;
    private javax.swing.JButton jButton37;
    private javax.swing.JButton jButton38;
    private javax.swing.JButton jButton39;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton40;
    private javax.swing.JButton jButton41;
    private javax.swing.JButton jButton42;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JButton jButton8;
    private javax.swing.JButton jButton9;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    // End of variables declaration//GEN-END:variables
}