// let dbl = document.querySelector("#dbl");
// dbl.ondblclick = () => {
//     console.log("used event handler#1 function");
//     alert("Yolo");
// };  
// dbl.ondblclick = () => {
//     console.log("used event handler#2 function");
//     alert("Hoi");
// }
let dbl = document.querySelector("#dbl");
dbl.ondblclick = (event) => {
    console.log(event);
    console.log(event.type);
    console.log(event.target);
    console.log(event.clintx, event.clinty);
    alert("New Yolo");
}
