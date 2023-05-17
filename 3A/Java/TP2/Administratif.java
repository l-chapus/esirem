public class Administratif extends Personnel {
	protected String fonction;
	
	public Administratif (String fonction ,String service , String nom , String prenom , int age ){
		super(service, nom, prenom, age);
		this . fonction = fonction;
	}
	public String getFonction () {
		return this.fonction;
	}
	public void setFonction (String fonction) {
		this.fonction = fonction;
	}

	public void ouMeTrouver(){
		System.out.println("Le plus facile c'est de passer à mon bureau.");
	}

	public String toString () {
		String info = nom + " " + prenom + " a " + age + " ans est dans le service : " + service + " avec la fonction de : " + fonction;
		return info;
	}
}