# re-tailwind-rn

Rescript bindings for [rn-tailwind](https://github.com/vadimdemedes/tailwind-rn)

## Install

```bash
npm install tailwind-rn re-tailwind-rn
```

## bsconfig.json

```
{
  ...
  "bs-dependencies": ["reason-react-native", "reason-react", "re-tailwind-rn"]
}
```

## Usage

Use the `Tw` module

```reason
open ReactNative;

[@react.component]
let make = () =>
  <SafeAreaView style={Tw.make("h-full")}>
    <View style={Tw.make("pt-12 items-center")}>
      <View style={Tw.make("bg-blue-200 px-3 py-1 rounded-full")}>
        <Text style={Tw.make("text-blue-800 font-semibold")}>
          "Hello Tailwind"->React.string
        </Text>
      </View>
    </View>
  </SafeAreaView>;
```

## Usage with [custom config](https://github.com/vadimdemedes/tailwind-rn#customization)

```reason
open ReactNative;

[@module "./styles.json"] external stylesConfig: Js.Json.t = "default"

let tw = Tw.create(stylesConfig)

[@react.component]
let make = () =>
  <SafeAreaView style={tw.make("h-full")}>
    <View style={tw.make("pt-12 items-center")}>
      <View style={tw.make("bg-blue-200 px-3 py-1 rounded-full")}>
        <Text style={tw.make("text-blue-800 font-semibold")}>
          "Hello Tailwind"->React.string
        </Text>
      </View>
    </View>
  </SafeAreaView>;
```

### Recommended to use with [re-classnames](https://github.com/MinimaHQ/re-classnames)

```reason
open ReactNative;

type styles = {
  container: Style.t,
  text: Style.t,
};

let styles = {
  container: Tw.make("flex justify-start rounded-md px-2 py-2 my-2"),
  text: Tw.make("flex-grow text-gray-700 font-medium px-2"),
};


[@react.component]
let make = (~todo, ~completed) => {
  <View style={styles.container}>
    <Text
      style={Style.array([|
        styles.text,
        Tw.(make("line-through"->Cn.on(completed))),
      |])}>
      todo->React.string
    </Text>
  </View>;
};
```

## API

### make

```reason
type make = string => ReactNative.Style.t;
```

### color

```reason
type color = string => string;
```

### create

```reason
type created = {
  [@as "tailwind"]
  make,
  [@as "getColor"]
  color,
};

type create = Js.Json.t => created;
```
