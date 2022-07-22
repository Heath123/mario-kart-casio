#include "./configurableConstants.h"

double turnSpeed = 0.002;
double drag = 0.9;
double offRoadDrag = 0.7;
double angularDrag = 0.9;
double maxPower = 0.1;
double powerFactor = 0.001;
double boostMaxPower = 0.15;
double boostPowerFactor = 0.002;
double maxSteerNormal = 1;
double minSteerDrift = 0.15;
double neutralSteerDrift = 0.77;
double maxSteerDrift = 1.7;

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

EM_JS(void, initSliders, (), {
  window.constantValues = {};
  const container = document.getElementById("sliderContainer");
  // Create a slider for each constant
  const constants = [
    {
      name: "turnSpeed",
      min: 0,
      max: 0.01,
      step: 0.0001,
      value: 0.002,
      description: "Turning this up makes the kart... well... turn faster. Acts as a multiplier for all the turn angle options (maxSteerNormal, minSteerDrift, neutralSteerDrift and maxSteerDrift).",
    },
    // Inverted
    {
      name: "drag",
      min: 0,
      max: 1,
      step: 0.01,
      value: 0.1,
      description: "A multiplier that is applied to the velocity every frame. This also affects the top speed, so if you adjust this, you'll probably want to adjust maxPower unless this is intended (as in the case of being off road)."
    },
    {
      name: "offRoadDrag",
      min: 0,
      max: 1,
      step: 0.01,
      value: 0.3,
      description: "Used instead of drag when the kart is off road."
    },
    {
      name: "angularDrag",
      min: 0,
      max: 1,
      step: 0.01,
      value: 0.9,
      description: "A multiplier that is applied to the angular velocity every frame. Turning this up makes turning feel more slippery, as you will continue to turn for a bit after you stop pressing a direction."
    },
    {
      name: "maxPower",
      min: 0,
      max: 0.5,
      step: 0.0001,
      value: 0.1,
      description: "The maximum acceleration that can be applied to the kart - this is the main way of changing the top speed, along with drag."
    },
    {
      name: "powerFactor",
      min: 0,
      max: 0.01,
      step: 0.0001,
      value: 0.001,
      description: "Controls the speed at which the power changes. Affects how quickly you can get back up to speed after you stop."
    },
    {
      name: "boostMaxPower",
      min: 0,
      max: 0.5,
      step: 0.0001,
      value: 0.15,
      description: "Used instead of maxPower when the kart is boosting from a drift (and in the future, other things like mushrooms and boost pads)."
    },
    {
      name: "boostPowerFactor",
      min: 0,
      max: 0.01,
      step: 0.0001,
      value: 0.002,
      description: "Used instead of powerFactor when the kart is boosting."
    },
    {
      name: "maxSteerNormal",
      min: 0,
      max: 3,
      step: 0.01,
      value: 1,
      description: "The maximum steering angle that can be applied to the kart when not drifting."
    },
    {
      name: "minSteerDrift",
      min: -3,
      max: 3,
      step: 0.01,
      value: 0.15,
      description: "The minimum steering angle that can be applied to the kart when the kart is drifting, when holding the button in the opposite direction of the drift. Having this lower makes it easier to not go off the track, and having it higher makes it harder (which can be good, because there should be some challenge to drifting so you have to earn the boosts). Having this negative means you can steer in the opposite direction of the drift, which makes things even easier."
    },
    {
      name: "neutralSteerDrift",
      min: 0,
      max: 3,
      step: 0.01,
      value: 0.77,
      description: "The steering angle that is applied to the kart when the kart is drifting and not turning."
    },
    {
      name: "maxSteerDrift",
      min: 0,
      max: 3,
      step: 0.01,
      value: 1.7,
      description: "The maximum steering angle that can be applied to the kart when the kart is drifting, by holding the button in the same direction as the drift."
    }
  ];
  for (const constant of constants) {
    window.constantValues[constant.name] = constant.value;
    const label = document.createElement("label");
    label.innerHTML = constant.name;
    label.setAttribute("for", constant.name);
    const slider = document.createElement("input");
    slider.type = "range";
    slider.min = constant.min;
    slider.max = constant.max;
    slider.step = constant.step;
    slider.value = constant.value;
    slider.style.width = "400px";
    slider.id = constant.name;
    const valueIndicator = document.createElement("div");
    valueIndicator.id = constant.name + "Value";
    valueIndicator.innerHTML = constant.value;
    slider.oninput = function() {
      window.constantValues[constant.name] = Number(this.value);
      valueIndicator.innerHTML = this.value;
      if (this.value != constant.value) {
        // Make the text orange if the value has changed
        valueIndicator.style.color = "orange";
      } else {
        valueIndicator.style.color = "black";
      }
    };
    const description = document.createElement("div");
    description.innerHTML = constant.description;
    const resetButton = document.createElement("button");
    resetButton.innerHTML = "Reset";
    resetButton.onclick = function() {
      window.constantValues[constant.name] = constant.value;
      slider.value = constant.value;
      valueIndicator.innerHTML = constant.value;
      valueIndicator.style.color = "black";
    };
    container.appendChild(label);
    container.appendChild(document.createElement("br"));
    container.appendChild(slider);
    container.appendChild(valueIndicator);
    container.appendChild(description);
    container.appendChild(resetButton);
    container.appendChild(document.createElement("hr"));
  }
})

void updateConstants() {
  turnSpeed = EM_ASM_DOUBLE({
    return window.constantValues.turnSpeed;
  });
  drag = 1.0 - EM_ASM_DOUBLE({
    return window.constantValues.drag;
  });
  offRoadDrag = 1.0 - EM_ASM_DOUBLE({
    return window.constantValues.offRoadDrag;
  });
  angularDrag = EM_ASM_DOUBLE({
    return window.constantValues.angularDrag;
  });
  maxPower = EM_ASM_DOUBLE({
    return window.constantValues.maxPower;
  });
  powerFactor = EM_ASM_DOUBLE({
    return window.constantValues.powerFactor;
  });
  boostMaxPower = EM_ASM_DOUBLE({
    return window.constantValues.boostMaxPower;
  });
  boostPowerFactor = EM_ASM_DOUBLE({
    return window.constantValues.boostPowerFactor;
  });
  maxSteerNormal = EM_ASM_DOUBLE({
    return window.constantValues.maxSteerNormal;
  });
  minSteerDrift = EM_ASM_DOUBLE({
    return window.constantValues.minSteerDrift;
  });
  neutralSteerDrift = EM_ASM_DOUBLE({
    return window.constantValues.neutralSteerDrift;
  });
  maxSteerDrift = EM_ASM_DOUBLE({
    return window.constantValues.maxSteerDrift;
  });
}
#else
void initSliders() {}
void updateConstants() {}
#endif
