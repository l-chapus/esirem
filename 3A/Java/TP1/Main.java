import java.util.ArrayList;
import java.util.Collections;

class Main
{
	public static void main(String[] args) {
		Cours c1 = new Cours("UE41","Informatique",20);
		Cours c2 = new Cours("UE42","Electronique Numérique",35);
		Cours c3 = new Cours("UE51","Ondes et propagation",40);
		Cours c4 = new Cours("UE52","Certification CCNA1",30);
		Cours c5 = new Cours("UE61","Traitement du signal",25);
		Cours c6 = new Cours("UE62","Projet",24);
		Cours c7 = new Cours("UE71","Anglais",12);

		ArrayList<Cours> listeCours = new ArrayList<Cours>();

		listeCours.add(c1);
		listeCours.add(c2);
		listeCours.add(c3);
		listeCours.add(c4);
		listeCours.add(c5);
		listeCours.add(c6);
		listeCours.add(c7);

		Formation esirem3A = new Formation("3A_S6","Semestre 6, ESIREM",listeCours);
		
		//System.out.println(esirem3A);
		//listeCours.remove(1);
		//System.out.println(esirem3A);
		//System.out.println(esirem3A.getListeCours().get(1));
		
		System.out.println(esirem3A);

		Collections.sort(esirem3A.getListeCours());

		System.out.println(esirem3A);
	}
}

