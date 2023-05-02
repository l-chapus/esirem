import { View } from "../views/view.js";
import { Controller } from "../controllers/controller.js";

window.addEventListener("load",() => {
    const ControllerPage = new Controller();
    const viewPage = new View(ControllerPage);
})