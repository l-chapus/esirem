const canvas = document.querySelector("canvas");
const context = canvas.getContext("2d");

function resize() {
    canvas.width = canvas.clientWidth;
    canvas.height = canvas.clientHeight;
    drawSolarSystem();
}

window.addEventListener("resize", () => {
    resize();
});

function drawSquare() {

    // Starts the drawing of the shape
    context.beginPath();
    /*
    Prepares the draweing of a rectangle starting at (0 ; 0) with 100 pixels width
    and 100 pixels height
    */
    context.rect(0, 0, 100, 100);
    // Sets the color of filling
    context.fillStyle = "#FF0000";
    // Fills the square
    context.fill();
}

function drawCelestialBody(celestialBody) {

    //Saves the context in its current state [*0]
    context.save();
    context.rotate(celestialBody.orbitalAngle);
    //Translates the coordinate system with the vector (celestialBody.distance ; 0)
    context.translate(celestialBody.distance, 0);
    if (celestialBody.hasShadow) {
        //Draws a black disque which will be the shadowed part of the planet
        context.beginPath();
        context.arc(0, 0, celestialBody.radius, 0, 2 * Math.PI);
        context.fillStyle = "#000000";
        context.fill();


        // Create a radial gradient
        context.beginPath();
        context.arc(0, 0, celestialBody.radius, 0, 2 * Math.PI);

        const gradient = context.createRadialGradient(0, 0, celestialBody.radius, 0, 0, 2 * celestialBody.radius);

        // Add color stops
        gradient.addColorStop(0, 'rgba(0, 0, 0, 0)');
        gradient.addColorStop(0.7, 'rgba(0, 0, 0, 0)');
        gradient.addColorStop(1, 'rgba(0, 0, 0, 1)');

        // Use the gradient as a fill style
        context.fillStyle = gradient;
        context.fill();


        //Saves the current context [*1]
        context.save();

        //Prepares the drawing of the mask
        context.beginPath();
        context.arc(-celestialBody.radius * 2, 0, celestialBody.radius * 2, 0, 2 * Math.PI);

        //Create a mask from the previous prepared drawing
        context.clip();
    }

    //Starts the drawing
    context.beginPath();

    //Prepare the drawing of a complete circle
    context.arc(0, 0, celestialBody.radius, 0, 2 * Math.PI);

    //Creates a pattern from the texture of the celestial body
    const pattern = context.createPattern(celestialBody.texture, "no-repeat");
    const coef = (celestialBody.radius * 2) / celestialBody.texture.width;

    //Saves the current context [*2]
    context.save();

    //Rotates the celestial body on its own axis
    context.rotate(celestialBody.rotationAngle);

    //Moves and scales the coordinate system to apply the pattern
    context.translate(-celestialBody.radius, -celestialBody.radius);
    context.scale(coef, coef);

    //Sets the filling color
    context.fillStyle = pattern; //celestialBody.color;

    //Fills the circle
    context.fill();

    //Restores the context [*2]
    context.restore();
    if (celestialBody.hasShadow) {
        //Restores the context and disable the mask [*1]
        context.restore();
    }
    //Draws each satellite of the celestial body
    celestialBody.satellites.forEach((satellite) => {
        drawOrbit(satellite);
        drawCelestialBody(satellite);
    });
    //Restores the context on its initial state [*0]
    context.restore();
}


function drawSolarSystem() {
    //Saves the context
    context.save();
    //Moves the coordinate system to the center of the canvas
    context.translate(canvas.width / 2, canvas.height / 2);
    //Draws the solar system starting with the sun
    drawCelestialBody(solarSystem.sun);
    //Restores the context to its states at the previous call of save
    context.restore();
}


function drawOrbit(celestialBody) {
    // Starts the drawing
    context.beginPath();
    // Prepare the drawing of a complete circle
    context.arc(0, 0, celestialBody.distance, 0, 2 * Math.PI);
    // Sets the outline color of the circle
    context.strokeStyle = "#333333";
    // Draws the outline of the circle
    context.stroke();
}


function animate(lastUpdateTime) {
    // Gets the number of milliseconds elapsed from the beginning of the program
    const now = performance.now();
    // Computes the elpased time from the last update.
    // If lastUpdateTime is equel to 0, it is the first frame, so update is not required.
    const elapsedTime = lastUpdateTime === 0 ? 0 : now - lastUpdateTime;
    // Clears the canvas
    context.clearRect(0, 0, canvas.width, canvas.height);
    // Draws the solar system
    drawSolarSystem();
    // Updates celestial bodies position
    solarSystem.sun.update(elapsedTime);
    // Requests a new frame as soon as possible
    requestAnimationFrame(() => { animate(now) });
}


window.addEventListener("load", () => {
    solarSystem.sun.initTexture().then(() => {
        resize();
        animate(0);
    });
});