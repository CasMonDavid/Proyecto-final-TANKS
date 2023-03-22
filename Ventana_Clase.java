package TrabajoClase;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Ventana extends JFrame {
	
	public Ventana() {
		
		//Ventana
		this.setVisible(true);
		this.setSize(500,700);
		this.setLocationRelativeTo(null);
		this.setTitle("Registrar nuevo usuario");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(null);
		
		JButton btn1 = new JButton("Enviar");
		btn1.setSize(70,30);
		btn1.setLocation(215,600);
		btn1.setOpaque(true);
		//btn1.setBackground(Color.red);
		btn1.setForeground(Color.blue);
		this.add(btn1);
		
		JLabel tittle = new JLabel("Registro de nuevo usuario",JLabel.CENTER);
		tittle.setFont(new Font("Comic sans",Font.BOLD,30));
		tittle.setSize(400,50);
		tittle.setLocation(50,20);
		tittle.setOpaque(true);
		tittle.setBackground(null);
		this.add(tittle);
		
		JLabel etiquetaUsuario = new JLabel("Escriba su nombre de usuario");
		etiquetaUsuario.setFont(new Font("Comic sans",Font.ITALIC,15));
		etiquetaUsuario.setSize(300,20);
		etiquetaUsuario.setLocation(135,105);
		etiquetaUsuario.setOpaque(true);
		etiquetaUsuario.setBackground(null);
		this.add(etiquetaUsuario);
		
		JLabel etiquetaContra = new JLabel("Cree su contraseña");
		etiquetaContra.setFont(new Font("Comic sans",Font.ITALIC,15));
		etiquetaContra.setSize(200,50);
		etiquetaContra.setLocation(135,150);
		etiquetaContra.setOpaque(true);
		etiquetaContra.setBackground(null);
		this.add(etiquetaContra);
		
		JLabel etiquetaDescripcion = new JLabel("Añade una pequeña descripcion a tu nuevo usuario");
		etiquetaDescripcion.setFont(new Font("Comic sans",Font.ITALIC,15));
		etiquetaDescripcion.setSize(340,20);
		etiquetaDescripcion.setLocation(90,230);
		etiquetaDescripcion.setOpaque(true);
		etiquetaDescripcion.setBackground(null);
		this.add(etiquetaDescripcion);
		
		JTextArea descripcion = new JTextArea();
		descripcion.setFont(new Font("Arial",Font.PLAIN,15));
		descripcion.setSize(340, 100);
		descripcion.setLocation(90,260);
		descripcion.setOpaque(true);
		descripcion.setBackground(Color.cyan);
		descripcion.setForeground(Color.black);
		this.add(descripcion);
		
		JLabel etiquetaMaterias = new JLabel("Seleccione sus materias");
		etiquetaMaterias.setFont(new Font("Comic sans",Font.ITALIC,15));
		etiquetaMaterias.setSize(340,20);
		etiquetaMaterias.setLocation(90,370);
		etiquetaMaterias.setOpaque(true);
		etiquetaMaterias.setBackground(null);
		this.add(etiquetaMaterias);
		
		JCheckBox materia1 = new JCheckBox("Programación 3");
		materia1.setSize(140, 30);
		materia1.setLocation(100,400);
		materia1.setOpaque(true);
		materia1.setBackground(Color.LIGHT_GRAY);
		this.add(materia1);
		
		JCheckBox materia2 = new JCheckBox("Matemáticas");
		materia2.setSize(140, 30);
		materia2.setLocation(250,400);
		materia2.setOpaque(true);
		materia2.setBackground(Color.LIGHT_GRAY);
		this.add(materia2);
		
		JRadioButton sexHombre = new JRadioButton("Hombre");
		sexHombre.setSize(80,40);
		sexHombre.setLocation(140, 440);
		sexHombre.setOpaque(true);
		this.add(sexHombre);
		
		JRadioButton sexMujer = new JRadioButton("Mujer");
		sexMujer.setSize(80,40);
		sexMujer.setLocation(270, 440);
		sexMujer.setOpaque(true);
		this.add(sexMujer);
		
		JTextField username = new JTextField("Nombre de usuario");
		username.setSize(230,30);
		username.setLocation(135,130);
		username.setForeground(Color.gray);
		this.add(username);
		
		JPasswordField userpassword = new JPasswordField();
		userpassword.setSize(230,30);
		userpassword.setLocation(135,190);
		this.add(userpassword);
		
		/* Bienvenida del trabajo anterior
		 * 
		JLabel bienvenida = new JLabel();
		bienvenida.setFont(new Font("Arial",Font.ITALIC,15));
		bienvenida.setSize(300,50);
		bienvenida.setLocation(125,300);
		bienvenida.setOpaque(true);
		bienvenida.setBackground(null);
		this.add(bienvenida);
		
		JLabel loading = new JLabel("Espere un momento....");
		loading.setFont(new Font("Arial",Font.BOLD,15));
		loading.setSize(250,50);
		loading.setLocation(320,460);
		loading.setForeground(Color.GRAY);
		loading.setOpaque(true);
		loading.setBackground(null);
		loading.setVisible(false);
		this.add(loading); */
		
		btn1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				/*bienvenida.setText("Bienvenido de nuevo " + username.getText());
				loading.setVisible(true);*/
			}
		});
		
		this.repaint();
	}
}