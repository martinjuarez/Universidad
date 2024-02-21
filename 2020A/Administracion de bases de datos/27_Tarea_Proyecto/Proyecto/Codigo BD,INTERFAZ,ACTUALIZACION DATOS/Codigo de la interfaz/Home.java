package Ventanas;

import Modelo.Ejemplares;
import controlador.SqlLibros;
import Modelo.libros;
import Modelo.usuarios;
import controlador.SqlLibros;

public class Home extends javax.swing.JFrame {

    public static usuarios mod;
    public static libro frmLib;
    public static ejemplar frmEjem;
    public static autor frmAut;
    public static prestamo frmPres; 

    public Home() {
        initComponents();
        this.setLocationRelativeTo(null);
    }

    public Home(usuarios mod) {
        initComponents();
        this.setLocationRelativeTo(null);
        this.mod = mod;
        Nombre.setText(mod.getNombre());
        Rol.setText(mod.getUsuario_tipo());

        if (mod.getId_tipo() == 2) {
            MenuMultas.setVisible(false);
        } else if (mod.getId_tipo() == 3) {
            AgregarLibro.setVisible(false);
            ModificarLibro.setVisible(false);
            EliminarLibro.setVisible(false);
            AgregarAutor.setVisible(false);
            ModificarAutor.setVisible(false);
            EliminarAutor.setVisible(false);
            AgregarEjemplar.setVisible(false);
            ModificarEjemplar.setVisible(false);
            EliminarEjemplar.setVisible(false);
            MenuReservacion.setVisible(false);
            MenuPrestamos.setVisible(false);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Nombre = new javax.swing.JLabel();
        Rol = new javax.swing.JLabel();
        Wallpaper = new javax.swing.JLabel();
        MenuBar1 = new javax.swing.JMenuBar();
        MenuLibros = new javax.swing.JMenu();
        AgregarLibro = new javax.swing.JMenuItem();
        ModificarLibro = new javax.swing.JMenuItem();
        EliminarLibro = new javax.swing.JMenuItem();
        ListaLibro = new javax.swing.JMenuItem();
        MenuAutores = new javax.swing.JMenu();
        AgregarAutor = new javax.swing.JMenuItem();
        ModificarAutor = new javax.swing.JMenuItem();
        EliminarAutor = new javax.swing.JMenuItem();
        ListaAutor = new javax.swing.JMenuItem();
        MenuEjemplares = new javax.swing.JMenu();
        AgregarEjemplar = new javax.swing.JMenuItem();
        ModificarEjemplar = new javax.swing.JMenuItem();
        EliminarEjemplar = new javax.swing.JMenuItem();
        ListaEjemplares = new javax.swing.JMenuItem();
        MenuPrestamos = new javax.swing.JMenu();
        AgregarPrestamo = new javax.swing.JMenuItem();
        ModificarPrestamo = new javax.swing.JMenuItem();
        EliminarPrestamo = new javax.swing.JMenuItem();
        ListaPrestamo = new javax.swing.JMenuItem();
        MenuReservacion = new javax.swing.JMenu();
        AgregarReservacion = new javax.swing.JMenuItem();
        MenuMultas = new javax.swing.JMenu();
        ListarMultas = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(930, 602));
        setSize(new java.awt.Dimension(0, 0));
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Nombre.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Nombre.setForeground(new java.awt.Color(255, 102, 102));
        getContentPane().add(Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 150, -1, -1));

        Rol.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Rol.setForeground(new java.awt.Color(255, 102, 102));
        getContentPane().add(Rol, new org.netbeans.lib.awtextra.AbsoluteConstraints(60, 250, -1, -1));

        Wallpaper.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(Wallpaper, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        MenuLibros.setText("Libros");

        AgregarLibro.setText("Agregar Libro");
        AgregarLibro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarLibroActionPerformed(evt);
            }
        });
        MenuLibros.add(AgregarLibro);

        ModificarLibro.setText("Modificar Libro");
        ModificarLibro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarLibroActionPerformed(evt);
            }
        });
        MenuLibros.add(ModificarLibro);

        EliminarLibro.setText("Eliminar Libro");
        EliminarLibro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarLibroActionPerformed(evt);
            }
        });
        MenuLibros.add(EliminarLibro);

        ListaLibro.setText("Lista Libros");
        ListaLibro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ListaLibroActionPerformed(evt);
            }
        });
        MenuLibros.add(ListaLibro);

        MenuBar1.add(MenuLibros);

        MenuAutores.setText("Autores");
        MenuAutores.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                MenuAutoresActionPerformed(evt);
            }
        });

        AgregarAutor.setText("Agregar Autor");
        AgregarAutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarAutorActionPerformed(evt);
            }
        });
        MenuAutores.add(AgregarAutor);

        ModificarAutor.setText("Modificar Autor");
        ModificarAutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarAutorActionPerformed(evt);
            }
        });
        MenuAutores.add(ModificarAutor);

        EliminarAutor.setText("Eliminar Autor");
        EliminarAutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarAutorActionPerformed(evt);
            }
        });
        MenuAutores.add(EliminarAutor);

        ListaAutor.setText("Lista Autores");
        ListaAutor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ListaAutorActionPerformed(evt);
            }
        });
        MenuAutores.add(ListaAutor);

        MenuBar1.add(MenuAutores);

        MenuEjemplares.setText("Ejemplares");

        AgregarEjemplar.setText("Agregar Ejemplar");
        AgregarEjemplar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarEjemplarActionPerformed(evt);
            }
        });
        MenuEjemplares.add(AgregarEjemplar);

        ModificarEjemplar.setText("Modificar Ejemplar");
        ModificarEjemplar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarEjemplarActionPerformed(evt);
            }
        });
        MenuEjemplares.add(ModificarEjemplar);

        EliminarEjemplar.setText("Eliminar Ejemplar");
        EliminarEjemplar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarEjemplarActionPerformed(evt);
            }
        });
        MenuEjemplares.add(EliminarEjemplar);

        ListaEjemplares.setText("Lista Ejemplares");
        ListaEjemplares.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ListaEjemplaresActionPerformed(evt);
            }
        });
        MenuEjemplares.add(ListaEjemplares);

        MenuBar1.add(MenuEjemplares);

        MenuPrestamos.setText("Prestamos");

        AgregarPrestamo.setText("Agregar Prestamo");
        AgregarPrestamo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarPrestamoActionPerformed(evt);
            }
        });
        MenuPrestamos.add(AgregarPrestamo);

        ModificarPrestamo.setText("Modificar Prestamo");
        ModificarPrestamo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarPrestamoActionPerformed(evt);
            }
        });
        MenuPrestamos.add(ModificarPrestamo);

        EliminarPrestamo.setText("Eliminar Prestamo");
        EliminarPrestamo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarPrestamoActionPerformed(evt);
            }
        });
        MenuPrestamos.add(EliminarPrestamo);

        ListaPrestamo.setText("Lista Prestamo");
        ListaPrestamo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ListaPrestamoActionPerformed(evt);
            }
        });
        MenuPrestamos.add(ListaPrestamo);

        MenuBar1.add(MenuPrestamos);

        MenuReservacion.setText("Reservacion");

        AgregarReservacion.setText("Agregar Reservacion");
        AgregarReservacion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarReservacionActionPerformed(evt);
            }
        });
        MenuReservacion.add(AgregarReservacion);

        MenuBar1.add(MenuReservacion);

        MenuMultas.setText("Multas");

        ListarMultas.setText("Lista Multas");
        MenuMultas.add(ListarMultas);

        MenuBar1.add(MenuMultas);

        setJMenuBar(MenuBar1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ModificarLibroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarLibroActionPerformed
        if (frmLib == null) {
            frmLib = new libro();
            frmLib.Guardar.setVisible(false);
            frmLib.Eliminar.setVisible(false);
            frmLib.Buscar.setVisible(false);
            frmLib.Titulo.setText("Modificar");
            frmLib.setVisible(true);
        }
    }//GEN-LAST:event_ModificarLibroActionPerformed

    private void AgregarReservacionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarReservacionActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_AgregarReservacionActionPerformed

    private void ListaLibroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ListaLibroActionPerformed
        if (frmLib == null) {
            frmLib = new libro();
            frmLib.Guardar.setVisible(false);
            frmLib.Modificar.setVisible(false);
            frmLib.Eliminar.setVisible(false);
            frmLib.Titulo.setText("Listar");
            frmLib.setVisible(true);
        }
    }//GEN-LAST:event_ListaLibroActionPerformed

    private void AgregarLibroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarLibroActionPerformed
        if (frmLib == null) {
            frmLib = new libro();
            frmLib.Field1.setVisible(false);
            frmLib.Isbn.setVisible(false);
            frmLib.Modificar.setVisible(false);
            frmLib.Eliminar.setVisible(false);
            frmLib.Buscar.setVisible(false);
            frmLib.Titulo.setText("Agregar");
            frmLib.setVisible(true);
        }
    }//GEN-LAST:event_AgregarLibroActionPerformed

    private void EliminarLibroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarLibroActionPerformed
        if (frmLib == null) {
            frmLib = new libro();
            frmLib.Guardar.setVisible(false);
            frmLib.Modificar.setVisible(false);
            frmLib.Buscar.setVisible(false);
            frmLib.Titulo.setText("Eliminar");
            frmLib.setVisible(true);
        }
    }//GEN-LAST:event_EliminarLibroActionPerformed

    private void AgregarAutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarAutorActionPerformed
        if (frmAut == null) {
            frmAut = new autor();
            frmAut.Id_usuario.setVisible(false);
            frmAut.Field1.setVisible(false);
            frmAut.Modificar.setVisible(false);
            frmAut.Eliminar.setVisible(false);
            frmAut.Buscar.setVisible(false);
            frmAut.Titulo.setText("Agregar");
            frmAut.setVisible(true);
        }
    }//GEN-LAST:event_AgregarAutorActionPerformed

    private void AgregarEjemplarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarEjemplarActionPerformed
        if (frmEjem == null) {
            frmEjem = new ejemplar();
            frmEjem.Field1.setVisible(false);
            frmEjem.Ejemplar.setVisible(false);
            frmEjem.Modificar.setVisible(false);
            frmEjem.Eliminar.setVisible(false);
            frmEjem.Buscar.setVisible(false);
            frmEjem.Titulo.setText("Agregar");
            frmEjem.setVisible(true);
        }
    }//GEN-LAST:event_AgregarEjemplarActionPerformed

    private void ModificarEjemplarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarEjemplarActionPerformed
        if (frmEjem == null) {
            frmEjem = new ejemplar();
            frmEjem.Guardar.setVisible(false);
            frmEjem.Eliminar.setVisible(false);
            frmEjem.Buscar.setVisible(false);
            frmEjem.Titulo.setText("Modificar");
            frmEjem.setVisible(true);
        }
    }//GEN-LAST:event_ModificarEjemplarActionPerformed

    private void EliminarEjemplarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarEjemplarActionPerformed
        if (frmEjem == null) {
            frmEjem = new ejemplar();
            frmEjem.Guardar.setVisible(false);
            frmEjem.Modificar.setVisible(false);
            frmEjem.Buscar.setVisible(false);
            frmEjem.Titulo.setText("Eliminar");
            frmEjem.setVisible(true);
        }
    }//GEN-LAST:event_EliminarEjemplarActionPerformed

    private void ListaEjemplaresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ListaEjemplaresActionPerformed
        frmEjem = new ejemplar();
        frmEjem.Guardar.setVisible(false);
        frmEjem.Modificar.setVisible(false);
        frmEjem.Eliminar.setVisible(false);
        frmEjem.Titulo.setText("Listar");
        frmEjem.setVisible(true);
    }//GEN-LAST:event_ListaEjemplaresActionPerformed

    private void ModificarAutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarAutorActionPerformed
        if (frmAut == null) {
            frmAut = new autor();
            frmAut.Guardar.setVisible(false);
            frmAut.Eliminar.setVisible(false);
            frmAut.Buscar.setVisible(false);
            frmAut.Titulo.setText("Modificar");
            frmAut.setVisible(true);
        }
    }//GEN-LAST:event_ModificarAutorActionPerformed

    private void EliminarAutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarAutorActionPerformed
        if (frmAut == null) {
            frmAut = new autor();
            frmAut.Guardar.setVisible(false);
            frmAut.Modificar.setVisible(false);
            frmAut.Buscar.setVisible(false);
            frmAut.Titulo.setText("Eliminar");
            frmAut.setVisible(true);
        }
    }//GEN-LAST:event_EliminarAutorActionPerformed

    private void ListaAutorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ListaAutorActionPerformed
        if (frmAut == null) {
            frmAut = new autor();
            frmAut.Guardar.setVisible(false);
            frmAut.Modificar.setVisible(false);
            frmAut.Eliminar.setVisible(false);
            frmAut.Titulo.setText("Lista");
            frmAut.setVisible(true);
        }
    }//GEN-LAST:event_ListaAutorActionPerformed

    private void MenuAutoresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_MenuAutoresActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_MenuAutoresActionPerformed

    private void AgregarPrestamoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarPrestamoActionPerformed
        if (frmPres == null) {
            frmPres = new prestamo();
            frmPres.Modificar.setVisible(false);
            frmPres.Eliminar.setVisible(false);
            frmPres.Buscar.setVisible(false);
            frmPres.Titulo.setText("Agregar");
            frmPres.setVisible(true);
        }
    }//GEN-LAST:event_AgregarPrestamoActionPerformed

    private void ModificarPrestamoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarPrestamoActionPerformed
        if (frmPres == null) {
            frmPres = new prestamo();
            frmPres.Guardar.setVisible(false);
            frmPres.Eliminar.setVisible(false);
            frmPres.Buscar.setVisible(false);
            frmPres.Titulo.setText("Modificar");
            frmPres.setVisible(true);
        }
    }//GEN-LAST:event_ModificarPrestamoActionPerformed

    private void EliminarPrestamoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarPrestamoActionPerformed
        if (frmPres == null) {
            frmPres = new prestamo();
            frmPres.Guardar.setVisible(false);
            frmPres.Modificar.setVisible(false);
            frmPres.Buscar.setVisible(false);
            frmPres.Titulo.setText("Eliminar");
            frmPres.setVisible(true);
        }
    }//GEN-LAST:event_EliminarPrestamoActionPerformed

    private void ListaPrestamoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ListaPrestamoActionPerformed
        if (frmPres == null) {
            frmPres = new prestamo();
            frmPres.Guardar.setVisible(false);
            frmPres.Modificar.setVisible(false);
            frmPres.Eliminar.setVisible(false);
            frmPres.Titulo.setText("Listar");
            frmPres.setVisible(true);
        }
    }//GEN-LAST:event_ListaPrestamoActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Home().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem AgregarAutor;
    private javax.swing.JMenuItem AgregarEjemplar;
    private javax.swing.JMenuItem AgregarLibro;
    private javax.swing.JMenuItem AgregarPrestamo;
    private javax.swing.JMenuItem AgregarReservacion;
    private javax.swing.JMenuItem EliminarAutor;
    private javax.swing.JMenuItem EliminarEjemplar;
    private javax.swing.JMenuItem EliminarLibro;
    private javax.swing.JMenuItem EliminarPrestamo;
    private javax.swing.JMenuItem ListaAutor;
    private javax.swing.JMenuItem ListaEjemplares;
    private javax.swing.JMenuItem ListaLibro;
    private javax.swing.JMenuItem ListaPrestamo;
    private javax.swing.JMenuItem ListarMultas;
    private javax.swing.JMenu MenuAutores;
    private javax.swing.JMenuBar MenuBar1;
    private javax.swing.JMenu MenuEjemplares;
    private javax.swing.JMenu MenuLibros;
    private javax.swing.JMenu MenuMultas;
    private javax.swing.JMenu MenuPrestamos;
    private javax.swing.JMenu MenuReservacion;
    private javax.swing.JMenuItem ModificarAutor;
    private javax.swing.JMenuItem ModificarEjemplar;
    private javax.swing.JMenuItem ModificarLibro;
    private javax.swing.JMenuItem ModificarPrestamo;
    private javax.swing.JLabel Nombre;
    private javax.swing.JLabel Rol;
    private javax.swing.JLabel Wallpaper;
    // End of variables declaration//GEN-END:variables
}
