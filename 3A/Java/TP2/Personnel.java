public class Personnel extends Personne {
	protected String service;

	public Personnel (String service, String nom , String prenom , int age ){
	super(nom, prenom, age);
	this . service = service ;
	}

	public String getService () {
		return this.service;
	}
	public void getService (String service) {
		this.service = service;
	}

	public void afficherAge () {
		System .out . println ( "Ce personnel a " + age + " an(s)" );
	}
	public void afficherPrenom () {
		System .out . println ( "Ce personnel a pour prénom " + prenom );
	}
	
	public String toString () {
		String info = nom + " " + prenom + " a " + age + " ans est dans le service : " + service ;
		return info;
	}

}

