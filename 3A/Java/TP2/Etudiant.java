public class Etudiant extends Personne {
	protected String promotion;
	protected int nbAbsences;
	
	public Etudiant (String promotion , int nbAbsences, String nom , String prenom , int age ){
		super(nom, prenom, age);
		this . promotion = promotion;
		this . nbAbsences = nbAbsences;
	}
	public String getPromotion () {
		return this.promotion;
	}
	public int getNbAbsences () {
		return this.nbAbsences;
	}
	public void setPromotion (String promotion) {
		this.promotion = promotion;
	}
	public void setNbAbsences (int nbAbsences) {
		this.nbAbsences = nbAbsences;
	}


	public void ouMeTrouver(){
		System.out.println("Je suis en cours tous les jours, sauf les jeudis après-midis (je fais du sport, mais c'est comme un cours car j'aime le sport).");
	}

	public String toString () {
		String info = nom + " " + prenom + " a " + age + " ans est dans la promotion : " + promotion + " et il a " + nbAbsences + " absence(s)." ;
		return info;
	}
}