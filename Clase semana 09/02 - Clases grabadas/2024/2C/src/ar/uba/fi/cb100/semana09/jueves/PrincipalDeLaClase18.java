package ar.uba.fi.cb100.semana09.jueves;

import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;

public class PrincipalDeLaClase18 {

	
	public static void main(String[] args) {
		//El color esta en (r, g, b) (cantidad de rojo, cantidad de verde, cantidad de azul)
		//255,0,0
		
		int largo = 100;
		int[][] matrizRGB = new int[largo][largo];
		for(int i = 0; i < largo; i++) {
			for( int j = 0; j < largo; j++) {
				int r = (i * 255) / largo;
				int g = (j * 255) / largo;
				int b = 111;
				
				//int rgb = (r << 16) | (g << 8) | b;
				int rgb = 16711680;
				matrizRGB[i][j] = rgb;
			}
		}
		
        BufferedImage image = new BufferedImage(largo, largo, BufferedImage.TYPE_INT_RGB);
        
		for(int i = 0; i < largo; i++) {
			for( int j = 0; j < largo; j++) {
				image.setRGB(i, j, matrizRGB[i][j]);
			}
		}
		
		try {
			File archivo = new File("salida4.bmp");
			ImageIO.write(image, "bmp", archivo);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		try {
			File inputFile = new File("input.bmp");
	        image = ImageIO.read(inputFile);
	        
	        int ancho = image.getWidth();
	        int alto = image.getHeight();
	        
	        for(int i = 0; i < ancho; i++) {
	        	for(int j = 0; j < alto; j++) {
	        		int rgb = image.getRGB(i,  j);
	        	}
	        }
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
}
