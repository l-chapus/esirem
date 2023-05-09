public class Cours implements Comparable{
	private String _code;
	private String _intitule;
	private float _volHoraire;

	public Cours(String code, String intitule, int volHoraire){
		this._code = code;
		this._intitule = intitule;
		this._volHoraire = volHoraire;
	}

	@Override
	public int compareTo(Object obj) {
		String intitule =  ((Cours)obj).getIntitule();
		return this._intitule.compareTo(intitule);
	}

	public String getCode(){
		return this._code;
	}
	public String getIntitule(){
		return this._intitule;
	}
	public float getVolHoraire(){
		return this._volHoraire;
	}
	public void setCode(String code){
		this._code = code;
	}
	public void setIntitule(String intitule){
		this._intitule = intitule;
	}
	public void setVolHoraire(float volHoraire){
		this._volHoraire = volHoraire;
	}

	public String toString(){
		return ("Code du cours : " + this._code + " , intitulé du cours : " + this._intitule + ", volume horaire : " + this._volHoraire);
	}
}