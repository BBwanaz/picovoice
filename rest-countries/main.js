/**
 * This function gets called on click of "Search" button. It retrieves a list containing a country's neighbours,
 * calls the getCapitals function and displays the capitals as returned.
 */
async function searchCountry() {
  let country = document.getElementById("myText").value;
  let url = "https://restcountries.eu/rest/v2/name/"

  let countryData = await fetch(url.concat(country))  
                    .then(res => res.json())
                    .then(data => data)
                    .catch(err => console.log("Error:", err));
  let capitals = await getCapitals(countryData)                       //retrieve capitals
  displayCapitals(capitals)                                           //display capitals
}

/**
 * This function combines the ISO code for a country with the list of ISO codes for neighbouring countries
 * and retrieves the capitals.
 * @param  {object} country JSON object containing all the country's data from the REST API
 * @return {list}           a list of capitals 
 */

async function getCapitals(country){
  let url = "https://restcountries.eu/rest/v2/alpha?codes="
  let codes = country[0].borders;                                       //get neighbours
  let code = country[0].alpha3Code;                                     //get ISO code

  codes.unshift(code);                                                  //add country ISO code to the front of neighbour's ISO codes

  url = url.concat(codes.join(';'))                                     //join list of codes separated by ; and concatenate with url
  let countries = await fetch(url)
                        .then(res => res.json())
                        .then(data => data)
                        .catch(err => console.log("Error:", err));

  //countries.forEach(item => console.log(item.capital))
  let result = countries.map(a => a.capital);                           //retrieve a list of capitals
  return result;

}
/**
 * This takes a list of capitals and adds them to the inner HTML of the "capitals" element
 * @param  {list} arg1 list of capitals
 */


function displayCapitals(capitals){
  document.getElementById("capitals").innerHTML = capitals;

}

