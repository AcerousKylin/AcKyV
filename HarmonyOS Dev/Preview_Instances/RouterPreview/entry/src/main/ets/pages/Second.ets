import router from '@ohos.router'

@Entry
@Component
struct Second {
  private content: string = "This is Page 2."

  @State text: string = router.getParams()["text"]
  @State data: object = router.getParams()["data"]
  @State secondaryData: string = ''

  build() {
    Flex({
      direction: FlexDirection.Column,
      alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center}) {
      Text(`${this.content}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Text(`${this.content}`)
        .fontSize(50)
        .onClick(() => {
          this.secondaryData = (this.data["array"][2]).toString()
        })
        .margin({ top: 20})
      Text(`Data that Page 1 send is: ${this.secondaryData}`)
        .fontSize(20)
        .margin( {top: 20})
        .backgroundColor("red")
    }
    .width("100%")
    .height("100%")
  }
}