import java.util.ArrayList;

class Formation
{
	private String _code;
	private String _nom;
	private ArrayList<Cours> _listeCours;
	
	public Formation(String code, String nom, ArrayList<Cours> listeCours){
		this._code = code;
		this._nom = nom;
		this._listeCours = listeCours;
	}
	public String getCode(){
		return this._code;
	}
	public String getNom(){
		return this._nom;
	}
	public ArrayList<Cours> getListeCours(){
		return this._listeCours;
	}
	public void setCode(String code){
		this._code = code;
	}
	public void setNom(String nom){
		this._nom = nom;
	}
	public void setListeCours(ArrayList<Cours> listeCours){
		this._listeCours = listeCours;
	}

	public String toString(){
		String text;
		text = "Code de la formation :" + this._code + ", nom de la formation : " + this._nom + " liste des cours :";
		for (int k=0;k<_listeCours.size();k++) {
			text = text + '\n' + "     " + _listeCours.get(k).toString();
		}
		return text;
	}
	public void addCours(Cours C){
		_listeCours.add(C);
	}
}