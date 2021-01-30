import {
    Entity,
    Column,
    PrimaryGeneratedColumn,
    OneToMany,
    JoinColumn,
    OneToOne,
} from 'typeorm'
import { Review } from './Review'
import { OpeningTimes } from './OpeningTimes'
import { LocationMarker } from './LocationMarker'
import { BusinessImage } from './BusinessImage'

@Entity()
export class Business {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    name: string

    @Column()
    url: string

    @Column({ type: 'decimal', precision: 2, scale: 1 })
    averageRating: number

    @OneToOne(() => OpeningTimes)
    @JoinColumn()
    openingTimes: OpeningTimes

    @OneToOne(() => LocationMarker, (locationMarker) => locationMarker.business)
    locationMarker: LocationMarker

    @OneToMany(() => Review, (review) => review.business)
    reviews: Review[]

    @OneToMany(
        (type) => BusinessImage,
        (businessImage) => businessImage.business,
    )
    images: BusinessImage[]
}
