class Exec
{
	public static void main(String[] args) {
		Etudiant etu = new Etudiant("CHAPUS","Louka",21);

		try {
			etu . ajouterNote (12) ;
			etu . ajouterNote (9);
			etu . ajouterNote (7);
			etu . ajouterNote (19) ;
			}
		catch ( ErreurNotes e){
			System . out . println (" Gestionnaire d'exceptions demandE ... ");
			System . out . println (e.recuperMessageErreur());
		}
	}
}
