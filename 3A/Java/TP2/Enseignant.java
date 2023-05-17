public class Enseignant extends Personnel {
	protected String matierePrincipale;
	protected String matiereSecondaire;
	
	public Enseignant (String matierePrincipale ,String matiereSecondaire ,String service , String nom , String prenom , int age ){
		super(service, nom, prenom, age);
		this . matierePrincipale = matierePrincipale;
		this . matiereSecondaire = matiereSecondaire;
	}
	public String getmMatierePrincipale () {
		return this.matierePrincipale;
	}
	public String getMatiereSecondaire () {
		return this.matiereSecondaire;
	}
	public void setmMatierePrincipale (String matierePrincipale) {
		this.matierePrincipale = matierePrincipale;
	}
	public void setMatiereSecondaire (String matiereSecondaire) {
		this.matiereSecondaire = matiereSecondaire;
	}

	public void ouMeTrouver(){
		System.out.println("Ce n'est pas la peine de me chercher, je saurai vous trouver !");
	}
	public String toString () {
		String info = nom + " " + prenom + " a " + age + " ans est dans le service : " + service + " avec pour matière principale " + matierePrincipale + " et a pour mati-re secondaire " + matiereSecondaire;
		return info;
	}
}