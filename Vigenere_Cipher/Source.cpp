#include <iostream>
using namespace std;

//gerekli paremetrelerin tanimlandi�i Islem isimli yapi.
struct Islem
{
	int giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };
	double cekirdek_boyutu;
	double kayma_miktari;
	int cekirdek[100][100];
	double sonucboyut;
};
//struct� main i�inde kullanmak i�in tan�mlama 
Islem matris_islemi_parametre;
int giris_boyut = size(matris_islemi_parametre.giris); //matrisin boyutunu �l�me i�lemi bu satirda yapilir.
int carpim;
int x_ekseni = 0;
int y_ekseni = 0;
int islemicarp(int x_ekseni, int y_ekseni) //matrisi elemanlarinin �arpim islemini yapan fonksiyon.
{
	for (int i = 0; i < giris_boyut; i++) { //giri� elemanlari i�in yapilan tanimlama 
		for (int j = 0; j < giris_boyut; j++) {

			for (int a = 0; a < matris_islemi_parametre.cekirdek_boyutu; a++) { //�ekirdek elemanlari i�in for d�ng�s�
				for (int b = 0; b < matris_islemi_parametre.cekirdek_boyutu; b++) {

					if (i == a + y_ekseni && j == b + x_ekseni)
					{
						carpim += matris_islemi_parametre.giris[i][j] * matris_islemi_parametre.cekirdek[a][b];
					}
				}
			}
		}
	}
	return carpim;
}



int main()
{
	cout << "Lutfen Cekridek Boyutunu Giriniz:";
	cin >> matris_islemi_parametre.cekirdek_boyutu;
	cout << endl;
	cout << "Lutfen Kayma Miktarini Giriniz:";
	cin >> matris_islemi_parametre.kayma_miktari;
	cout << endl;

	matris_islemi_parametre.sonucboyut = ((giris_boyut - matris_islemi_parametre.cekirdek_boyutu) / matris_islemi_parametre.kayma_miktari) + 1;
	int sonucboyuttam = matris_islemi_parametre.sonucboyut;

	if (matris_islemi_parametre.sonucboyut == sonucboyuttam) //matris �arpiminin yapilip yapilmayacagini kontrol etme durumu.
	{

		for (int i = 0; i < matris_islemi_parametre.cekirdek_boyutu; i++) { //�ekirdek elemanlar�n� kullan�c�dan almak i�in d�nen d�ng�.
			for (int j = 0; j < matris_islemi_parametre.cekirdek_boyutu; j++) {
				cout << "Cekirdek" << "[" << i << "]" << "[" << j << "]" << "=";
				cin >> matris_islemi_parametre.cekirdek[i][j];
				cout << endl;
			}
		}

		cout << endl;

		for (int i = 0; i < matris_islemi_parametre.sonucboyut; i++) { //Sonuc matrisini olu�turmak i�in d�nen d�ng�

			for (int j = 0; j < matris_islemi_parametre.sonucboyut; j++) {


				cout << islemicarp(x_ekseni, y_ekseni) << '\t'; //�arpma fonksiyonun �a��r�lmas�
				x_ekseni = x_ekseni + matris_islemi_parametre.kayma_miktari;
				carpim = 0;

			}

			x_ekseni = 0;
			y_ekseni = y_ekseni + matris_islemi_parametre.kayma_miktari;

			cout << endl;
		}


	}
	else //kontrol durumu d���nda kalan elemanlar i�in yapilacak islemler
	{
		cout << "bu islem yapilamaz..." << endl;

	}

	system("pause");
}


