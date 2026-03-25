import router from '@ohos.router'

@Entry
@Component
struct First {
  async routePage() {

    let options = {
      url: 'pages/Second',
      params: {
        text: "This is a value from Page 1.",
        data: {
          array: [12, 48, 58]
        }
      }
    }

    try {
      await router.pushUrl(options)
    } catch (error) {
      console.info(` fail callback, code: ${error.code}, msg: ${error.msg}`)
    }

  }

  build() {

    Flex({
      direction: FlexDirection.Column,
      alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {

      Text("This is Page 1")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)

      Button() {
        Text("New Page")
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({ top: 20 })
      .backgroundColor("#ccc")
      .onClick(() => {
        this.routePage()
      })

    }
    .width("100%")
    .height("100%")

  }

}