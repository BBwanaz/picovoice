
async function searchCountry() {
  let country = document.getElementById("myText").value;
  let url = "https://restcountries.eu/rest/v2/name/"

  let countryData = await fetch(url.concat(country))
                    .then(res => res.json())
                    .then(data => data)
                    .catch(err => console.log("Error:", err));
  let capitals = await getCapitals(countryData)
  displayCapitals(capitals)
}

async function getCapitals(country){
  let url = "https://restcountries.eu/rest/v2/alpha?codes="
  let codes = country[0].borders;
  let code = country[0].alpha3Code;

  codes.unshift(code);

  url = url.concat(codes.join(';'))
  let countries = await fetch(url)
                        .then(res => res.json())
                        .then(data => data)
                        .catch(err => console.log("Error:", err));

  let capitals;
  //countries.forEach(item => console.log(item.capital))
  let result = countries.map(a => a.capital);
  return result;

}

function displayCapitals(capitals){
  document.getElementById("capitals").innerHTML = capitals;

}

