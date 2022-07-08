# custom_components
My collection of components for esphome. Cloned from [Ssieb's Custom Components Repo](https://github.com/ssieb/custom_components) With a few of my own added in

To use these components, use the [external components](https://esphome.io/components/external_components.html).

Example:
```yaml
external_components:
  - source:
      type: git
      url: https://github.com/cpyarger/custom_components
    components: [ ifan ifan04 ]
```

## My components 

includes; 

* ifan - provides simple support for the fan, buzzer, and light of an sonoff ifan04
* st7796 - WIP - provides support for the st7796 display, currently not working