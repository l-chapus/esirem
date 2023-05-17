class Execution
{
	public static void main(String[] args) {
		Etudiant e1 = new Etudiant("Pascal",4,"Dupont","Alice",21);
		Etudiant e2 = new Etudiant("Ohm",0,"Dujardin","Benjamin",22);
		Etudiant e3 = new Etudiant("Promotion inconnue",0,"Anonyme","Anonyme",-1);
		Etudiant e4 = new Etudiant("Promotion inconnue",0,"Anonyme","Anonyme",-1);

		Administratif a1 = new Administratif("secrétaire","informatique","Dupont","Béatrice",19);

		Enseignant ens1 = new Enseignant("informatique","électronique", "info", "Machin","Boris",36);

		//e1.ouMeTrouver();
		//a1.ouMeTrouver();
		//ens1.ouMeTrouver();

		Personne tab[] = new Personne[5];
		tab[0] = e1;
		tab[1] = e2;
		tab[2] = e3;
		tab[3] = a1;
		tab[4] = ens1;

		for(int k=0;k<5;k++){
			System.out.println(tab[k].toString());
		}
		
	}
}
