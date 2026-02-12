const box1 = document.getElementById('1');
box1.style.backgroundColor = 'red';
const box2 = document.getElementById('2');
box2.style.backgroundColor = 'blue';
const box3 = document.getElementById('3');
box3.style.backgroundColor = 'green';
box3.innerHTML = '<h1> Hello </h1>';
const box4 = document.getElementById('4');
box4.style.backgroundColor = 'yellow';

//creating new Element

const newParagraph = document.createElement('p');
newParagraph.innerText = 'World';
newParagraph.classList.add('box');
const container = document.getElementById('container');
container.appendChild(newParagraph);
newParagraph.style.backgroundColor = 'purple';


//const myBody  = document.body;
//console.log(myBody);
//const box2 = document.getElementById('2');
//console.log(box2);
//const divs = document.getElementsByTagName('p');
//console.log(divs);
//const boxes = document.getElementsByClassName('random');
//console.log(boxes);
//const random = document.querySelectorAll('.container .random');
//console.log(random);

