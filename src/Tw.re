type make = string => ReactNative.Style.t;
[@module "tailwind-rn"] external make: make = "default";

type color = string => string;
[@module "tailwind-rn"] external color: color = "getColor";

type created = {
  [@as "tailwind"]
  make,
  [@as "getColor"]
  color,
};

[@module "tailwind-rn"] external create: Js.Json.t => created = "create";
