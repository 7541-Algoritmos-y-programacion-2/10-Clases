package ar.uba.fi.cb100.semana01.jueves;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class AdministradorDeArchivosDeTexto {
	
	//c:\mis documentos\archivo.txt     /home/usuario/archivo.txt (ruta completa fija)
	//archivo.txt  (ruta relativa)  <-------
	//El archivo del tp lo tienen que entregar
	public static int[] leerLineasDeTexto(String nombreDeArchivo) {
		int cantidadDeLineas = 0;
		try(BufferedReader bufferedReader = new BufferedReader(new FileReader(nombreDeArchivo))) {
			String linea;			
			while ((linea = bufferedReader.readLine()) != null) {
				cantidadDeLineas++;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}	
		
		int[] resultado = new int[cantidadDeLineas];
		try(BufferedReader bufferedReader = new BufferedReader(new FileReader(nombreDeArchivo))) {
			String linea;	
			int i = 0;
			while ((linea = bufferedReader.readLine()) != null) {
				resultado[i++] = Integer.valueOf(linea);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return resultado;
	}
	
	public static void escribirLineasDeTexto(String nombreDeArchivo, 
												int[] vector,
												String lineaAdicional) {
		try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(nombreDeArchivo))) {
			for(int i = 0; i < vector.length; i++) {
				bufferedWriter.write( String.valueOf( vector[i]));
				bufferedWriter.newLine();
			}
			bufferedWriter.write(lineaAdicional);
		} catch (IOException e) {
			e.printStackTrace();
		} 	
	}
}
