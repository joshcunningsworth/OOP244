/*
 ============================================================================
 Name        : Molecule.h
 Author      : Josh Cunningham
 ============================================================================
 */


class Molecule{

	char symbol[21];
	char description[201];
	double weight;
	
	public:
		void display() const;
		void Setsymbol(char temp_symbol[21]);
		void Setdesc(char temp_desc[201]);
		void Setweight(double temp_weight);
};
