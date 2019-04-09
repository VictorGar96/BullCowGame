////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// ARCHIVO DE CABECERA /////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

/// Unreal String type and int type
using FString = std::string;
using int32   = int;

/// Esctructura con la cual comprobamos el n�mero de bulls and cows en cada intento
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows  = 0;
};

/// Clase
class FBullCowGame
{
/// M�todos y variables p�blicas
public:
	
	/// Constructor
	FBullCowGame();

	/// Funciones constantes
	int32   GetMaxTries()   const;
	int32   GetCurrentTry() const;
	FString GetHiddenWord() const;

	bool    IsGameWon()     ;
	/// Funci�n que resetea los valores
	void Reset();
	/// Funci�n que comprueba si la palabra introducida en cada intento es v�lida
	bool CheckGuessValidity(FString);
	/// 
	FBullCowCount SumitGuess(FString);

/// M�todos y variables privadas
private:

	/// See contructor for initialization 
	int32   myCurrentTry;
	int32   myMaxtries;
	FString myHiddenWord;

};