// 1
const suma = (a, b) => a + b;

function sumaZwykla(a, b) {
  return a + b;
}

const liczba1 = 5;
const liczba2 = 3;
console.log(`Suma: ${suma(liczba1, liczba2)}`);
console.log(`Suma (zwykła): ${sumaZwykla(liczba1, liczba2)}`);

// 2
const celsiusToFah = (celsius) => (celsius * 9/5) + 32;

function celsiusToFahZwykla(celsius) {
  return (celsius * 9/5) + 32;
}

const temperaturaCelsius = 25;
console.log(`Temperatura w °F: ${celsiusToFah(temperaturaCelsius)}`);
console.log(`Temperatura w °F (zwykła): ${celsiusToFahZwykla(temperaturaCelsius)}`);
//3
const rzutKostka = () => Math.floor(Math.random() * 6) + 1;


function rzutKostkaZwykla() {
  return Math.floor(Math.random() * 6) + 1;
}

console.log(`Wynik rzutu kostką: ${rzutKostka()}`);
console.log(`Wynik rzutu kostką (zwykła): ${rzutKostkaZwykla()}`);


// 4
const czyArmstrong = (liczba) => {
    const cyfry = liczba.toString().split('').map(Number);
    const sumaPoteg = cyfry.reduce((acc, cyfra) => acc + Math.pow(cyfra, cyfry.length), 0);
    return sumaPoteg === liczba;
  };
  

  function czyArmstrongZwykla(liczba) {
    const cyfry = liczba.toString().split('').map(Number);
    const sumaPoteg = cyfry.reduce((acc, cyfra) => acc + Math.pow(cyfra, cyfry.length), 0);
    return sumaPoteg === liczba;
  }
  
  const liczbaArmstrong = 153;
  console.log(`Czy ${liczbaArmstrong} to liczba Armstronga? ${czyArmstrong(liczbaArmstrong)}`);
  console.log(`Czy ${liczbaArmstrong} to liczba Armstronga (zwykła)? ${czyArmstrongZwykla(liczbaArmstrong)}`);

  //5
const poleTrojkata = (podstawa, wysokosc) => 0.5 * podstawa * wysokosc;

function poleTrojkataZwykla(podstawa, wysokosc) {
  return 0.5 * podstawa * wysokosc;
}

const dlugoscPodstawy = 10;
const wysokoscTrojkata = 6;
console.log(`Pole trójkąta: ${poleTrojkata(dlugoscPodstawy, wysokoscTrojkata)}`);
console.log(`Pole trójkąta (zwykła): ${poleTrojkataZwykla(dlugoscPodstawy, wysokoscTrojkata)}`);
