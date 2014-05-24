import java.util.ArrayList;
import java.io.*;
import java.util.Arrays;

public class Planets {
    public static void main( String[] args ) {

        String[] Planets = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto" }; 

        String[] arr = new String[9]; 

        ArrayList<String> planetList = new ArrayList<String>(); 
        ArrayList<String> nonPlanetList = new ArrayList<String>(); 

        for ( int i = 0; i < 9; i++ ) {
            Console console = System.console();
            arr[i] = console.readLine( "Enter a planet: " ); 
            
            if ( Arrays.asList( Planets ).contains( arr[i] ) ) {
                planetList.add( arr[i] );
            } else {
                System.out.println( arr[i] + " is not a planet." ); 
                nonPlanetList.add( arr[i] ); 
                i--; 
            }
        }
        System.out.println( "planets: " + planetList ); 
        System.out.println( "non planets: " + nonPlanetList ); 
    }
}
